//----------------------------おまじない
#pragma GCC optimize ("O3")
#pragma GCC target ("tune=native")
#pragma GCC target ("avx")
//----------------------------
#define FOR(i,j,n) for (int i=(j);i<(n);i++)
#define REP(i,n) for (int i=0;i<(n);i++)
#define REPN(i,n) for (int i=(n);i>0;i--)
#define I(n) scanf("%d", &(n))
#define LL(n) scanf("%lld", &(n))
#define pb(n) push_back((n))
#define mp(i,j) make_pair((i),(j))
#define eb(i,j) emplace_back((i),(j))
#include <bits/stdc++.h>
using namespace std;
//------------------------------typedef集
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;
typedef vector<vpi> vvpi;
typedef vector<vvi> vvvi;
typedef long long ll;
const int mod = 1000000009;

int n;
vvi ans;

int main(){
    cin >> n;
    int k = sqrt((double)n * 2);

    if (n == 1) {
        cout << "Yes" << endl;
        cout << 2 << endl;
        cout << "1 1" << endl;
        cout << "1 1" << endl;
    }else if (k * (k+1) == 2 * n){
        cout << "Yes" << endl;
        cout << k+1 << endl;

        ans.resize(k+1);
        int elm = 1;

        REP(i,k+1){
            int st = ans[i].size();
            FOR(j, st+1, k+1){
                ans[i].pb(elm);
                ans[j].pb(elm);
                elm++;
            }
            cout << k << " ";
            for (auto v: ans[i]) cout << v << " ";
            cout << endl;
        }

    } else {
        cout << "No" << endl;
    }
}
