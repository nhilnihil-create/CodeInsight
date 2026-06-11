#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i < (int)(n+1); i++)
const long long INF = 1LL << 60;
int main(){
    ll A,B,K;
    cin>>A>>B>>K;
    rep(i,K){
        if(i%2==1){
            if(B%2==1){
                B-=1;
            }
                A+=B/2;
                B/=2;
        }
        else{
            if(A%2==1){
                A-=1;
            }
                B+=A/2;
                A/=2;
            
        }
    }
    cout<<A<<" "<<B<<endl;
}
