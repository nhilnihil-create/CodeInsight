#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
#define reps(i,s,n) for(int i = s; i < n; i++)
#define rep(i,n) reps(i,0,n)
#define fi first
#define se second
#define mp make_pair
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;

ll N,M,H,W,K,A,B;
string S;
string alpha = "abcdefghijklmnopqrstuvwxyz";
string ALPHA = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main(){
    cin>>N;
    vec u(N,0), v(N,0);
    ll mod = 0;
    rep(i,N){
        cin>>A>>B;
        u[i] = A + B;
        v[i] = A - B;
        if(i == 0) {
            mod = abs(u[i])%2;
        }else if(mod != abs(u[i])%2) {
            cout<<-1<<endl;
            return 0;
        }
    }
    vec d(32-mod,1);
    reps(i,2-mod,32-mod) d[i] = d[i-1] * 2;
    ll base = (1LL<<31)-mod;

    cout<<32-mod<<endl;
    rep(i,32-mod) cout<<d[i]<<' ';
    cout<<endl;

    vector<char> dir = {'L','D','U','R'};
    rep(i,N){
        u[i] += base;
        v[i] += base;
        rep(j,32-mod){
            if(j == -mod){
                cout<<'L';
                continue;
            }
            bool x = ((u[i] & (d[j]<<1)) != 0);
            bool y = ((v[i] & (d[j]<<1)) != 0);
            cout<<dir[x*2+y];
        }
        cout<<endl;
    }
}