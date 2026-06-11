#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for(int i=0;i<(int)n;i++)
#define PI acos(-1)
#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);
ll mod=1e9+7;
ll gcd(ll a, ll b){if(b==0) return a; return gcd(b, a%b);}
int main(){
    fast_io

    int h, w;
    cin>>h>>w;
    char s[h][w];
    rep(i,h){
        rep(j,w){
            cin>>s[i][j];
        }
    }
    int dx[4]={0, 1, 0, -1};
    int dy[4]={1, 0, -1, 0};

    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            
            if(s[i][j]=='#'){
                bool flag=false;
                for(int k=0;k<4;k++){
                    int nw=j+dx[k];
                    int nh=i+dy[k];
                    if(s[nh][nw]=='#'){
                        flag=true;
                    }
                }
                if(flag==false){
                    cout<<"No"<<endl;
                    return 0;
                }
            }
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}