#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#include <random>
#include <cassert>
#include <numeric>
#define ll long long int
#define LL unsigned long long
#define pb push_back
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
using namespace std;

int mx8[] = {0,0,1,-1,-1,1,-1,1};
int my8[] = {-1,1,0,0,-1,-1,1,1};
int mx4[] = {1,-1,0,0};
int my4[] = {0,0,-1,1};
const int MOD = 1000000007;



int main() {
    int n; cin >> n;
    vector<ll> a(n),b(n),d(n);
    vector<pair<ll,ll>> p(n);
    ll suma = 0, sumb = 0, cnt = 0, m = 0;
    rep(i,n) {
        cin >> a[i];
        suma += a[i];
    }
    rep(i,n) {
        cin >> b[i];
        sumb += b[i];
    }
    if(suma < sumb){
        cout << -1 << endl;
    }else{
        rep(i,n) {
            d[i] = a[i] - b[i];
            if(d[i] < 0) {
                m += d[i];
                cnt++;
            }
            p[i].first = d[i];
            p[i].second = i;
        }
        m *= -1;
        sort(p.rbegin(),p.rend());
        int j = 0;
        while(m>0){
            m -= p[j].first;
            j++;
        }
        cout << j + cnt << endl;
    }

}