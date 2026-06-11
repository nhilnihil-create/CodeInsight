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
    vector<vector<int>> c(3,vector<int>(3));
    int x=0,y=0,z=0;
    rep(i,3){
        rep(j,3){
            cin>>c[i][j];
            if(j==i) x+=c[i][j];
            else if(j==i+1||(j==0&&i==2)) y+=c[i][j];
            else z+=c[i][j];
        }
    }
    if(x==y&&y==z) cout<<"Yes";
    else cout<<"No";
}