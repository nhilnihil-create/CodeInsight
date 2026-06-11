//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
//using Graph = vector<vector<pair<ll,ll>>>;
const int mod =1e+9+7;

const int dy[4]={0,1,0,-1};
const int dx[4]={1,0,-1,0};
const ll INF=1e10;

int main(){
    ll n; cin>>n;
    vector<vector<ll>>a(n,vector<ll>(3));
    rep(i,n){
        cin>>a[i][1]>>a[i][2]>>a[i][0];
    }
    ll H,cnt=0;
    for(int i=0;i<=100;i++){
        for(int j=0;j<=100;j++){
            rep(k,n){
                if(a[k][0]==0)continue;
                H=a[k][0]+abs(a[k][1]-i)+abs(a[k][2]-j);
                break;
            }
              cnt=0;
            rep(k,n){
                if((H-abs(a[k][1]-i)-abs(a[k][2]-j))<=0&&a[k][0]==0)cnt++;
                else if((H-abs(a[k][1]-i)-abs(a[k][2]-j))==a[k][0])cnt++;
            }
            if(cnt==n&&H>=1){
                cout<<i<<" "<<j<<" "<<H<<endl;
                return 0;
            }
        }
    }
}









