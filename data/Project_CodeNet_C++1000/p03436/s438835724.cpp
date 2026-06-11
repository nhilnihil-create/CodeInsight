#include <bits/stdc++.h>
typedef long long ll;
#define ALL(l)  (l).begin(),(l).end()
#define rep(i,n) for(ll (i)=0;(i)<(n);(i)++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
using namespace std;

//const ll mod =  1000000007;
//const ll maxn = 1000000000;

//---------------------------------------------------------------------------------------------------
using vi = vector<int>; // intの1次元の型に vi という別名をつける
using vll = vector<ll>; // intの1次元の型に vi という別名をつける
using vvll = vector<vll>; // intの2次元の型に vvi という別名をつける
using vs = vector<string>; // stringの1次元の型に vs という別名をつける
using pll = pair<ll, ll>; // これ以降 pii という型名はpair<ll, ll> と同じ意味で使える
//---------------------------------------------------------------------------------------------------


int main() {
    
   
   int h,w,sx=0,sy=0,gx,gy,nw=0;
   
   cin>>h>>w;
 

   
    gx=w-1;gy=h-1;
    
    vvll d(h,vll(w,0));
    vvll d2(h,vll(w,0));
    d.at(0).at(0)=1;
    vvll maze(h,vll(w));
    rep(i,h){
        rep(j,w){
            char c;
            cin>>c;
            if(c=='#')maze.at(i).at(j)=1;
            else{
                maze.at(i).at(j)=0;
                nw++;
            } 
        }
    }

   
    queue<pll> q;
    q.push({sy,sx});
    
    vll dy={0,-1,0,1};

    vll dx={-1,0,1,0};

    while(!q.empty()){
        ll ny=q.front().first;
        ll nx=q.front().second;
        q.pop();
        //cout<<ny<<" "<<nx<<endl;;
        rep(i,4){
            ll x=nx+dx.at(i);
            ll y=ny+dy.at(i);
           
            if(0<=x&&x<w&&0<=y&&y<h){
                 
                if(maze.at(y).at(x)==0){
                     if(d.at(y).at(x)==0){
                         //cout<<y<<x<<endl;
                        d.at(y).at(x)=d.at(ny).at(nx)+1;
                        d2.at(y).at(x)=1;
                        q.push({y,x});
                     }
                }
            }
        }// cout<<endl;
    }

    
    if(d.at(gy).at(gx)==0)cout<<-1<<endl;
    else cout<<nw-d.at(gy).at(gx)<<endl;
    
    
    
}

