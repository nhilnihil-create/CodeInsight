#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
using P = pair<ll,ll>;
using ld=long double;

int main(){
   ll  h,w;cin >>h>>w;
   ll white=0;
   vector<vector<char>>s(h,vector<char>(w));
   vector<vector<ll>>d(h,vector<ll>(w,INF));
   d[0][0]=1;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >>s[i][j];
            if(s[i][j]=='.')white++;
        }
    }
   queue<P>que;que.push({0,0});
   while(!que.empty()){
       P pos=que.front();
       que.pop();
       ll x=pos.first;
       ll y=pos.second;
       ll pre=d[x][y];
       auto add=[&](ll x, ll y){
           if(x<0||x>=h)return ;
           if(y<0||y>=w)return;
           if(s[x][y]=='#')return;
           if(d[x][y]>pre+1){
               d[x][y]=pre+1;
               que.push({x,y});
           }
       };
       add(x+1,y);
       add(x-1,y);
       add(x,y+1);
       add(x,y-1);
   }
   if(d[h-1][w-1]==INF)cout <<-1<<endl;
   else cout <<white-d[h-1][w-1]<<endl;
   return 0;
}