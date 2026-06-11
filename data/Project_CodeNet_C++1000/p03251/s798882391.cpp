#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<utility>
#include<iomanip>
#include<map>
#include<cmath>
#include<cstdio>
#define rep(i,n) for(int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P = pair<int,int>;

int main(){
    int n,m,x,y,a,b;
    string ans = "War";
    cin >> n >> m >> x >> y;
    rep(i,n){
        cin >> a;
        if(a>x) x=a;
    }
    rep(i,m){
        cin >> b;
        if(b<y) y=b;
    }
    if(x < y)
        ans = "No War";
    cout << ans << endl;
    return 0;
}