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
    int a,b,cnt=0;
    string s;
    cin>>a>>b>>s;
    rep(i,a+b+1){
        if(s[i]=='-') cnt++;
    }
    if(cnt==1&&s[a]=='-') cout<<"Yes";
    else cout<<"No";
}