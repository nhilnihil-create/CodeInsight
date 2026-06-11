#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <typeinfo>
#include <numeric>
#include <functional>
#include <unordered_map>
#include <bitset>
#include <stack>


using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll INF = 1e16;
const ll MOD = 1e9 + 7;

#define REP(i, n) for(ll i = 0; i < n; i++)






int main(){
    ll n;
    cin >> n;
    vector<pair<ll, ll>> l(n), r(n);
    REP(i, n){
        cin >> l[i].first >> r[i].first;
        l[i].second = r[i].second = i;
    }
    
    sort(l.begin(), l.end(), greater<pair<ll, ll>>());
    sort(r.begin(), r.end());
    
    vector<bool> used1(n), used2(n);
    ll p1 = 0, sum1 = 0, li1 = 0, ri1 = 0, p2 = 0, sum2 = 0, li2 = 0, ri2 = 0;
    REP(i, n){
        if(i % 2 == 0){
            while(used1[l[li1].second]) li1++;
            sum1 += max(l[li1].first - p1, 0LL);
            used1[l[li1].second] = true;
            p1 = max(p1, l[li1].first);
            
            while(used2[r[ri2].second]) ri2++;
            sum2 += max(p2 - r[ri2].first, 0LL);
            used2[r[ri2].second] = true;
            p2 = min(p2, r[ri2].first);
        }
        else{
            while(used1[r[ri1].second]) ri1++;
            sum1 += max(p1 - r[ri1].first, 0LL);
            used1[r[ri1].second] = true;
            p1 = min(p1, r[ri1].first);
            
            while(used2[l[li2].second]) li2++;
            sum2 += max(l[li2].first - p2, 0LL);
            used2[l[li2].second] = true;
            p2 = max(p2, l[li2].first);
        }
        // cerr << sum1 << " " << p1 << " " << sum2 << " " << p2 << endl;
    }
    
    cout << max(sum1 + abs(p1), sum2 + abs(p2)) << endl;
}