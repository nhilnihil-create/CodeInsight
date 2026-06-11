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
    vector<int> h(n+1);
    int ans=0;
    repi(i,1,n+1){
        cin>>h[i];
        if(h[i-1]<h[i]) ans+=h[i]-h[i-1];
    }
    cout<<ans;
}