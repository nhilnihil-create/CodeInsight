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
string s;
string alpha = "abcdefghijklmnopqrstuvwxyz";
string ALPHA = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main(){
    cin>>s;
    N = s.size();
    vec S(N,0);
    rep(i,N){
        A = s[i] - '0';
        S[i] = A;
    }
    rep(i,N-1){
        if((S[i]^S[N-2-i]) == 1){
            cout<<-1<<endl;
            return 0;
        }
    }
    if((S[N-1] == 1) || (S[0] == 0)){
        cout<<-1<<endl;
        return 0;
    }
    ll last;
    rep(i,N-1){
        if(i == 0){
            cout<<"1 2"<<endl;
            last = 2;
        }else if(i < N/2){
            cout<<last<<' '<<i+2<<endl;
            if(S.at(i) == 1) last = i+2;
        }else{
            cout<<last<<' '<<i+2<<endl;
        }
    }
}