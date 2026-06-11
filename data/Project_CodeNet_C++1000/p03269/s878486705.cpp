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

ll N,M,H,W,K,A,B,L;
string S;
string alpha = "abcdefghijklmnopqrstuvwxyz";
string ALPHA = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main(){
    cin>>L;
    vec bit(20,0);
    ll e = 0;
    rep(i,20){
        bit[i] = (L>>i) & 1;
        e += bit[i];
    }
    for(int i = 19; i >= 0; --i){
        if(bit[i] == 1) {
            N = i;
            break;
        }
    }

    e += N * 2 - 1;
    cout<<N+1<<' '<<e<<endl;
    rep(i,N){
        cout<<i+1<<' '<<i+2<<' '<<0<<endl;
        cout<<i+1<<' '<<i+2<<' '<<(1LL<<i)<<endl;
    }
    ll w = L;
    rep(i,N){
        if(bit[i] == 1){
            w -= (1LL<<i);
            cout<<i+1<<' '<<N+1<<' '<<w<<endl;
        }
    }
}