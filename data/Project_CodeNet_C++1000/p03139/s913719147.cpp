#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(long long i=0; i<(long long)(n);i++)
#define rep2(i,s,n) for(long long i=(s); i<(long long)(n);i++)
#define mod 1000000007

int main() {
    int a,b,c;cin>>a>>b>>c;

    cout<<min(b,c)<<" ";
    if(a-max(b,c)>min(b,c)){
        cout<<0<<endl;
    }
    else {
        cout<<min(b,c)-(a-max(b,c))<<endl;
    }
}
