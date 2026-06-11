//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int main(){
    int h,w,n=0; cin>>h>>w;
    vector<vector<int>> a(h,vector<int>(w,0)),ans(h*w-1,vector<int>(4,0));
    rep(i,h)rep(j,w){
        cin>>a[i][j];
    }
    rep(i,h){
        if(i%2){
            for(int j=w-1;j>=1;j--){
                if(a[i][j]%2){
                    a[i][j]--; a[i][j-1]++;
                    ans[n]={i+1,j+1,i+1,j};
                    n++;
                }
            }
            if(i!=h-1 && a[i][0]%2){
                a[i][0]--; a[i+1][0]++;
                ans[n]={i+1,1,i+2,1};
                n++;
            }
        }
        else{
            for(int j=0;j<w-1;j++){
                if(a[i][j]%2){
                    a[i][j]--; a[i][j+1]++;
                    ans[n]={i+1,j+1,i+1,j+2};
                    n++;
                }
            }
            if(i!=h-1 && a[i][w-1]%2){
                a[i][w-1]--; a[i+1][w-1]++;
                ans[n]={i+1,w,i+2,w};
                n++;
            }
        }
    }
    cout<<n<<endl;
    rep(i,n){
        rep(j,3) cout<<ans[i][j]<<" ";
        cout<<ans[i][3]<<endl;
    }
}