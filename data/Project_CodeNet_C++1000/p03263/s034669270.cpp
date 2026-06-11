#include <bits/stdc++.h>
#include <cmath>
#include <map>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep2(i,a,n) for(int i=a;i<n;i++)
#define been(ix) (ix).begin(),(ix).end()
using namespace std;
typedef long long ll; 
typedef vector<int> vi;
typedef vector<long long> vl;
const ll INFL = 1e18;
const int INF = 1001001001; 
typedef pair<int,int> P;
#define foreach(ix,i) for(auto& (ix) : (i))
typedef long double ld;
const int mod =1000000007;
int main(){
    int h,w;
    cin>>h>>w;
    int a[h][w];
    int ans[300000][4];
    int cnt =0;
    rep(i,h)rep(j,w)cin>>a[i][j];
    rep(i,h)rep(j,w-1){
        if(a[i][j]%2!=0){
            a[i][j+1]++;
            ans[cnt][0]=i+1;
            ans[cnt][1]=j+1;
            ans[cnt][2]=i+1;
            ans[cnt][3]=j+2;
            cnt++;
        }
    }
    rep(i,h-1){
        if(a[i][w-1]%2!=0){
            a[i+1][w-1]++;
            ans[cnt][0]=i+1;
            ans[cnt][1]=w;
            ans[cnt][2]=i+2;
            ans[cnt][3]=w;
            cnt++;
        }
    }
    cout<<cnt<<endl;
    rep(i,cnt){
        rep(j,4){
            if(j!=3)cout<<ans[i][j]<<" ";
            else
            {
                cout<<ans[i][j];
            }
            
        }
        cout<<endl;
    }
    
    
}
