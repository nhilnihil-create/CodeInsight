#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(long long i=0; i<(long long)(n);i++)
#define rep2(i,s,n) for(long long i=(s); i<(long long)(n);i++)
#define mod 1000000007

int main() {
    int n;cin>>n;
    vector<int>a(n);
    double avr=0;
    rep(i,n){
        cin>>a[i];
        avr+=a[i];
    }
    avr /=n;

    double min=100;
    int ans=0;
    rep(i,n){
        if(abs(a[i]-avr)<min){
            min=abs(a[i]-avr);
            ans=i;
        }
    }
    cout<<ans<<endl;
}

