#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(long long i=0; i<(long long)(n);i++)
#define rep2(i,s,n) for(long long i=(s); i<(long long)(n);i++)
#define mod 1000000007

int main() {
    int a,b,k;cin>>a>>b>>k;

    rep(i,k){
        if(i%2==0){
            if(a%2!=0){
            a--;
            }
            b+=a/2;
            a/=2;
        }
        else {
            if(b%2!=0){
                b--;
            }
            a+=b/2;
            b/=2;
        }
    }
    cout<<a<<" "<<b<<endl;
}

