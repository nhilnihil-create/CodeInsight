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
    vector<int> t(n+1),x(n+1),y(n+1);
    repi(i,1,n+1){
        cin>>t[i]>>x[i]>>y[i];
        int td=abs(t[i]-t[i-1]),xd=abs(x[i]-x[i-1]),yd=abs(y[i]-y[i-1]);
        if(td%2!=(xd+yd)%2||td<xd+yd){
            cout<<"No"; return 0;
        }
    }
    cout<<"Yes";
}