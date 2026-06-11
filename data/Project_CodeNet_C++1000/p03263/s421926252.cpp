#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
ll mod=1e9+7;
using P=pair<int,int>;
struct op{int a,b,c,d;};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int h,w;cin>>h>>w;
    vector<vector<int>> a(h,vector<int>(w));
    vector<op> ans;
    int tot=0;
    rep(i,h)rep(j,w)cin>>a[i][j];
    rep(i,h){
        if(i){
            for(int j=w-1;j>=0;j--){
                if(i==h-1 && j==0)break;
                if(j!=0 && a[i][j]%2!=0){
                    a[i][j-1]++;
                    tot++;
                    ans.push_back({i,j,i,j-1});
                }
                else if(j==0 && a[i][j]%2!=0){
                    a[i+1][j]++;
                    tot++;
                    ans.push_back({i,j,i+1,j});
                }
            }
        }
        else {
            for(int j=0;j<w;j++){
                if(i==h-1 && j==w-1)break;
                if(j!=w-1 && a[i][j]%2!=0){
                    a[i][j+1]++;
                    tot++;
                    ans.push_back({i,j,i,j+1});
                }
                else if(j==w-1 && a[i][j]%2!=0){
                    a[i+1][j]++;
                    tot++;
                    ans.push_back({i,j,i+1,j});
                }
            }
        }
    }
    cout<<tot<<endl;
    rep(i,ans.size())cout<<ans[i].a+1<<' '<<ans[i].b+1<<' '<<ans[i].c+1<<' '<<ans[i].d+1<<endl;
    return 0;
}
