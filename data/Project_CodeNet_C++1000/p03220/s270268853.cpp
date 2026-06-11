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
    int n,t,a,ans;
    cin>>n>>t>>a;
    vector<int> h(n);
    double best=100000;
    rep(i,n){
        cin>>h[i];
        double idea=t-h[i]*0.006;
        if(best>abs(a-idea)){
            best=abs(a-idea);
            ans=i+1;
        }
    }
    cout<<ans;
}