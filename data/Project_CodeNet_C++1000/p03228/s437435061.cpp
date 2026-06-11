#include <bits/stdc++.h>
#include <string.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define FOR(i, m, n) for(int i = m; i < n; i++) 
#define mod 1000000007
#define pi 3.1415926535
typedef long long ll;

int main(){
    int A,B,K;
    cin>>A>>B>>K;
    rep(i,K){
        if(i%2==0){
            if(A%2==1){
                A--;
            }
            B+=A/2;
            A/=2;
        }else{
            if(B%2==1){
                B--;
            }
            A+=B/2;
            B/=2;
        }
    }

    cout<<A<<" "<<B<<endl;
    return 0;
}