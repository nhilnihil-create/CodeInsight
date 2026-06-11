#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    ll N;
    cin>>N;
    ll ans=0;
    ll G=0;
    rep(i,N+1){
        if(i==0){
            ans=2;
        }
        else if(i==1){
            G=1;
        }
        else{
            ll A=ans;
            ll B=G;
            G=A+B;
            ans=B;
        }
    }
    cout<<G<<endl;
}

