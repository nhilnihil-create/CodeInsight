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
    string s,t("keyence");
    cin>>s;
    int cnt=0,n=s.size();
    rep(i,n){
        if(s[i]==t[i]) cnt++;
        else break;
    }
    rep(i,n){
        if(s[n-1-i]==t[6-i]) cnt++;
        else break;
    }
    if(cnt>=7) cout<<"YES";
    else cout<<"NO";
}