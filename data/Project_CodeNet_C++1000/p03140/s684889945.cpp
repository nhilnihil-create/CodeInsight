#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(long long i=0; i<(long long)(n);i++)
#define rep2(i,s,n) for(long long i=(s); i<(long long)(n);i++)
#define mod 1000000007

int main() {
    int n;cin>>n;
    string a,b,c;
    cin>>a>>b>>c;

    int ans=0;

    rep(i,n){
        set<char>ss;
        ss.insert(a[i]);
        ss.insert(b[i]);
        ss.insert(c[i]);
        ans+=ss.size()-1;
    }
    cout<<ans<<endl;
}
