#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;
int main(){
    int n,m;
    cin>>n>>m;
    string s,t;
    cin>>s>>t;
    ll g=__gcd(n,m);
    ll l=n/g*m;
    for(int i=0,j=0; i<n; i+=n/g,j+=m/g){
        if(s[i]!=t[j]){
            cout<<-1<<endl;
            return 0;
        }
    }
    cout<<l<<endl;
}
