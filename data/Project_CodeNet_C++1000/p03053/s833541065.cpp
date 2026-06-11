// lcmとか__builtin_popcountとかはg++ -std=c++17 default.cppみたいなかんじで

#include <bits/stdc++.h>
#define mod 1000000007
#define INF 1001001001
#define ll long long
#define ln cout<<endl
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define rep(i,n) REP(i,0,n)
ll dx[4]={1,0,-1,0};
ll dy[4]={0,1,0,-1};
using namespace std;

int main() {
    cin.tie(0);
   	ios::sync_with_stdio(false);

    ll a,b,c,d,m,n,maxi=0,f=0,mini=INF,sum=0;
    ll h,w;
    cin>>h>>w;
    string str[h];
    ll chk[h][w];
    deque<pair<ll,ll>> q;
    rep(i,h) cin>>str[i];
    rep(i,h){
        rep(j,w){
            chk[i][j]=0;
            if(str[i][j]=='#'){
                chk[i][j]=1;
                q.push_back(make_pair(i,j));
            }
        }
    }
    //sum++;
    q.push_back(make_pair(-100,-100));
    while(q.size()!=1){
        pair<ll,ll> p=q.front();
        q.pop_front();
        if(p.first==-100){
            q.push_back(make_pair(-100,-100));
            sum++;
        }else{
            rep(i,4){
                if(p.first+dy[i]<0||p.second+dx[i]<0||p.first+dy[i]>h-1||p.second+dx[i]>w-1) continue;
                //cout<<p.first+dy[i]<<" "<<p.second+dx[i]<<endl;

                if(chk[p.first+dy[i]][p.second+dx[i]]==0){
                    q.push_back(make_pair(p.first+dy[i],p.second+dx[i]));
                    chk[p.first+dy[i]][p.second+dx[i]]=1;
                }
            }
        }
        //cout<<"loop";
    }
    cout<<sum<<endl;
    return 0;
}
