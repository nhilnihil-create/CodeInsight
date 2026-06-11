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
    int n;
    cin>>n;
    int l,sum=0,longest=0;
    rep(i,n){
        cin>>l;
        sum+=l;
        longest=max(longest,l);
    }
    if(longest<sum-longest) cout<<"Yes";
    else cout<<"No";
}