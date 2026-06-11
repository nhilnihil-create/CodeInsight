#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
#define reps(i,s,n) for(int i = s; i < n; i++)
#define rep(i,n) reps(i,0,n)
#define Rreps(i,n,e) for(int i = n - 1; i >= e; --i)
#define Rrep(i,n) Rreps(i,n,0)
#define ALL(a) a.begin(), a.end()
#define fi first
#define se second
#define mp make_pair
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;

ll N,M,H,W,K,Q,A,B;
string S;
//const ll MOD = 998244353;
const ll MOD = (1e+9) + 7;
const ll INF = 1LL << 60;
typedef pair<ll,ll> P;

int main(){
    cin>>H>>W>>N;
    vec x(N+1), y(N+1), ord(N+1);
    rep(i,N) cin>>x[i]>>y[i], --x[i], --y[i], ord[i] = i;
    x[N] = H;
    y[N] = 0;
    ord[N] = N;
    sort(ALL(ord), [&](int a, int b){
        if(x[a] == x[b]) return y[a] < y[b]; 
        return x[a] < x[b];
    });
    int id = 0, depth = 0;
    reps(i,1,H + 1){
        while(x[ord[id]] < i) ++id;
        if(x[ord[id]] == i) {
            if (y[ord[id]] <= depth) {
                cout << i << endl;
                return 0;
            }else if (y[ord[id]] > depth + 1) {
                ++depth;
            }
        }else{
            ++depth;
        }
    }
}