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
    string s,ans="AC";
    cin>>s;
    if(s[0]!='A') ans="WA";
    int cnt=0;
    for(int i=1;i<s.size();i++){
        if(isupper(s[i])){
            if(i==1||i==s.size()-1||s[i]!='C') ans="WA";
            cnt++;
        }
    }
    if(cnt!=1) ans="WA";
    cout<<ans;
}