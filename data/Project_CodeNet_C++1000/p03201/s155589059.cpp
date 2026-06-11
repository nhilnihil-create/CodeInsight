//Feet don't fail me now
//Take me to the finish line
//Oh, my heart, it breaks every step that I take
//But I'm hoping at the gates, they'll tell me
//that IOI gold is mine
#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <iterator>

#define ios ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0);
#define S second
#define F first
#define pb push_back
#define nl '\n'
#define NL cout << '\n';
#define EX exit(0)
#define all(s) s.begin(), s.end()
#define no_answer {cout << "NO"; exit(0);}
#define vectors vector<vector<llong> >
#define FOR(i, start, finish, k) for(llong i = start; i <= finish; i += k)

const long long MXN = 2e5 + 10;
const long long MNN = 1e4 + 520;
const long long MOD = 10007;
const long long INF = 1e18;
const long long OO = 1e9;

typedef long long llong;
typedef unsigned long long ullong;

using namespace std;

int n, ans, b[MXN];
map<int, int> mp;

int main(){
    ios;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> b[i];
        mp[b[i]]++;
    }
    sort(b + 1, b + n + 1);
    reverse(b + 1, b + n + 1);
    for(int i = 1; i <= n; i++){
        if(mp[b[i]] == 0) continue;
        mp[b[i]]--;
        for(int j = 30; j >= 0; j--){
            if((1 << j) < b[i]) break;
            if(mp[(1 << j) - b[i]] > 0){
                ans++;
                mp[(1 << j) - b[i]]--;
                break;
            }
        }
    }
    cout << ans;
}

