#include <bits/stdc++.h>
using namespace std;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ll long long
ll MOD=1000000007;
int inf=1000000000;
ll INF=10000000000000000;
int main(){
    int h,w,n;
    cin >> h >> w >> n;
    vector<int> a(h+1,inf);
    rep(i,n){
        int f,g;
        cin >> f >> g;
        a.at(f)=min(a.at(f),g);
    }
    int t=1,ans=h;
    for (int i=1;i<h;i++){
        if (a.at(i+1)<=t) {ans=i;break;}
        if (a.at(i+1)>t+1) t++;
    }
    cout << ans << endl;
}