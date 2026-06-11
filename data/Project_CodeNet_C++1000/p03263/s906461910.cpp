#include<bits/stdc++.h>
#define INFTY 10000000000
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
const int MOD=1000000007;
const int di[4] = {-1,0,1,0};
const int dj[4] = {0,-1,0,1};
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
int main(){
    int h,w;cin>>h>>w;
    int a[h][w];
    vector<pair<int,int>>b,c;
    rep(i,h)rep(j,w)cin>>a[i][j];
    int cnt=0;
    rep(i,h){
        if(i%2==0){
            rep(j,w){
                if(a[i][j]%2==0)continue;
                else if(j!=w-1){
                    b.push_back(make_pair(i,j));
                    c.push_back(make_pair(i,j+1));
                    cnt++;a[i][j+1]++;
                }
                else if(i!=h-1){
                    b.push_back(make_pair(i,j));
                    c.push_back(make_pair(i+1,j));
                    cnt++;a[i+1][j]++;
                }
            }
        }
        else{
            for (int j = w-1; j>=0; j--)
            {
                if(a[i][j]%2==0)continue;
                else if(j!=0){
                    b.push_back(make_pair(i,j));
                    c.push_back(make_pair(i,j-1));
                    cnt++;a[i][j-1]++;
                }
                else if(i!=h-1){
                    b.push_back(make_pair(i,j));
                    c.push_back(make_pair(i+1,j));
                    cnt++;a[i+1][j]++;
                }
            }
        }
    }
    cout<<cnt<<endl;
    rep(i,cnt){
        printf("%d %d %d %d\n",b[i].first+1,b[i].second+1,c[i].first+1,c[i].second+1);
    }
    return 0;
}