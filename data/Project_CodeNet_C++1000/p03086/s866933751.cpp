#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define all(x) (x).begin(), (x).end()
#define PI 3.14159265358979323846264338327950L
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
    string s; cin>>s;
    int cnt=0,ans=0;
    rep(i,s.size()){
        if(s[i]=='A'||s[i]=='C'||s[i]=='G'||s[i]=='T') cnt++;
        else{
            ans=max(ans,cnt);
            cnt=0;
        }
        if(i==s.size()-1) ans=max(ans,cnt);
    }
    cout<<ans; 
}