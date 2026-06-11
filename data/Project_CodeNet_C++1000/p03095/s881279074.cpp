#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define all(x) (x).begin(), (x).end()
#define PI 3.14159265358979323846264338327950L
#define NUM 1000000007
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
    int n;
    string s;
    cin>>n>>s;
    map<char,int> a;
    rep(i,n) a[s[i]]++;
    ll ans=1;
    for(auto &b:a){
        ans*=b.second+1;
        ans%=NUM;
    }
    cout<<ans-1;
}