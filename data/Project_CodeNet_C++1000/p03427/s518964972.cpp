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
    string s;
    cin>>s;
    int n=s.size();
    vector<int> a(n);
    rep(i,n) a[i]=s[i]-'0';
    int ans,cnt=0;
    repi(i,1,n) if(a[i]==9) cnt++;
    if(cnt==n-1) ans=a[0]+9*(n-1);
    else ans=a[0]+9*(n-1)-1;
    cout<<ans;
}