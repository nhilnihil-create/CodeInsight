#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <functional>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000


int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    vector<int> v[31];
    rep(i, N) {
        int K; cin >> K;
        while(K--) {
            int A; cin >> A;
            A--;
            v[i].push_back(A);
        }
    }
    int ans = 0;
    rep(i, M) {
        bool ok = true;
        rep(j, N) {
            bool exist = false;
            for(auto& e: v[j]) {
                if(e == i) exist = true;
            }
            if(!exist) ok = false;
        }
        ans += ok;
    }
    cout << ans << endl;

    return 0;
}
