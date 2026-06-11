#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;
int main(){
    long a,b,k;
    cin>>a>>b>>k;
    for(int i=1; i<=k; ++i){
        if(i%2==1){
            a/=2;
            b+=a;
        }
        else{
            b/=2;
            a+=b;
        }
    }
    cout<<a<<" "<<b<<endl;
}