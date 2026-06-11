#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()
typedef long long LL;
typedef pair<LL,LL> P;
const LL mod=1000000007;
const LL LINF=1ll<<60;
const int INF=1<<30;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};



int main(){
    int h,w,n;cin >> w >> h >> n;
    vector<vector<int>> a(h);
    for (int i = 0; i < n; i++) {
        int x,y;cin >> x >> y;
        x--,y--;
        a[y].pb(x);
    }
    int ans = w;
    int x = 0;
    for (int i = 0; i < h; i++) {
        if(x>=w) break;
        if(a[i].size()){
            sort(ALL(a[i]));
            int t = 0;
            while(t<a[i].size()&&a[i][t]<x){
                t++;
            }
            if(t < a[i].size()) ans = min(ans,a[i][t]);
        }
        if(i+1<h&&a[i+1].size()){
            int t = 0;
            x++;
            sort(ALL(a[i+1]));
            while(t<a[i+1].size()&&a[i+1][t]<x){
                t++;
            }
            if(t<a[i+1].size()){
                if(a[i+1][t]==x){
                    while(t<a[i+1].size()&&a[i+1][t]==x){
                        t++;
                        x++;
                    }
                }
            }
        }
        else{
            x++;
        }
    }
    cout << ans << endl;
    return 0;
}
