#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int  n,m,x,y;
    cin>>n>>m>>x>>y;
    vector<int>xn(n);
    rep(i,n){
        cin>>xn[i];
    }
    vector<int>ym(m);
    rep(j,m){
        cin>>ym[j];
    }
    xn.push_back(x);
    ym.push_back(y);
    sort(xn.begin(),xn.end());
    sort(ym.begin(),ym.end());
    if(xn[n]<ym[0])cout<<"No War"<<endl;
    else cout<<"War"<<endl;

    return 0;
}