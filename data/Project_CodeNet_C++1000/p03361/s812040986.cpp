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
    int h,w;
    cin>>h>>w;
    char s[h][w];
    rep(i,h){
        rep(j,w) cin>>s[i][j];
    }
    rep(i,h){
        rep(j,w){
            if(s[i][j]=='#'&&s[i][j]!=s[i][j-1]&&s[i][j]!=s[i][j+1]&&s[i][j]!=s[i-1][j]&&s[i][j]!=s[i+1][j]){
                cout<<"No"; return 0;
            }
        }
    }
    cout<<"Yes";
}