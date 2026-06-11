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
    int n,q;
    string s;
    cin>>n>>q>>s;
    vector<int> a(n);
    repi(i,1,n){
        a[i]=a[i-1];
        if(s[i-1]=='A'&&s[i]=='C') a[i]++;
    }
    int l,r;
    rep(i,q){
        cin>>l>>r;
        cout<<a[r-1]-a[l-1]<<endl;
    }
}