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
    string s,t;
    cin>>s>>t;
    char tmp;
    int n=s.size();
    bool flag=false;
    rep(i,n){
        tmp=s[n-1];
        for(int j=n-1;j>0;j--){
            s[j]=s[j-1];
        }
        s[0]=tmp;
        if(s==t) flag=true;
    }
    if(flag) cout<<"Yes";
    else cout<<"No";
}