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
    int n; cin>>n;
    vector<string> w(n);
    rep(i,n) cin>>w[i];
    int cnt=0;
    rep(i,n-1){
        if(w[i].back()!=w[i+1].front()){
            cout<<"No"; return 0;
        }
        rep(j,n){
            if(w[i]==w[j]) cnt++;
        }
    }
    if(cnt==n-1) cout<<"Yes";
    else cout<<"No";
}