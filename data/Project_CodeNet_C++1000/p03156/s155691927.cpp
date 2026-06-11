#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(long long i=0; i<(long long)(n);i++)
#define rep2(i,s,n) for(long long i=(s); i<(long long)(n);i++)
#define mod 1000000007

int main() {
    int n,a,b;
    cin>>n>>a>>b;

    int cnta=0,cntb=0,cntc=0;

    rep(i,n){
        int p;
        cin>>p;
        if(p<=a){
            cnta++;
        }
        else if (p<=b) {
           cntb++;
        }
        else {
            cntc++;
        }
    }
    int ans=min({cnta,cntb,cntc});
    cout<<ans<<endl;
}
