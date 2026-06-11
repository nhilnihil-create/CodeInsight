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
    ll h,w; cin>>h>>w;
    vector<vector<ll>>a(h,vector<ll>(w));
    rep(i,h){
        rep(j,w){
            cin>>a[i][j];
        }
    }
    vector<vector<ll>>ans(h*w*10,vector<ll>(4));
    ll cnt=0;
    ll ny,nx;
    rep(i,h){
        if(i%2==0){
        rep(j,w){
            if(a[i][j]%2==0)continue;
            else if(h%2!=0&&i==h-1&&j==w-1)break;
            a[i][j]--;
            if(j+1<=w-1){
                a[i][j+1]++;
                ny=i;
                nx=j+1;
            }
            else{
                a[i+1][j]++;
                ny=i+1;
                nx=j;
            }
            ans[cnt][0]=i;
            ans[cnt][1]=j;
            ans[cnt][2]=ny;
            ans[cnt][3]=nx;
            cnt++;
        }
        }
        else{
            for(int j=w-1;0<=j;j--){
            if(a[i][j]%2==0)continue;
            else if(h%2==0&&i==h-1&&j==0)break;
            a[i][j]--;
            if(j-1>=0){
                a[i][j-1]++;
                ny=i;
                nx=j-1;
            }
            else{
                a[i+1][j]++;
                ny=i+1;
                nx=j;
            }
            ans[cnt][0]=i;
            ans[cnt][1]=j;
            ans[cnt][2]=ny;
            ans[cnt][3]=nx;
            cnt++;
        }
        }

    }
    /*rep(i,h){
        rep(j,w){
            cout<<a[i][j];
        }
        cout<<endl;
    }
    return 0;*/
    a.resize(cnt);
    cout<<cnt<<endl;
    rep(i,cnt){
        cout<<ans[i][0]+1<<" "<<ans[i][1]+1<<" "<<ans[i][2]+1<<" "<<ans[i][3]+1<<endl;
    }
}









