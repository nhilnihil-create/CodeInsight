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
   ll h,w;
   cin >>h>>w;
   vector<string>s(h);
    for (int i = 0; i < h; ++i) {
        cin >>s[i];
    }
   ll white=0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if(s[i][j]=='.')white++;
        }
    }
   vector<vector<ll>>d(h,vector<ll>(w,INF));
   queue<P>que;
   d[0][0]=0;
   ll dx[4]={0,0,1,-1};
   ll dy[4]={1,-1,0,0};
   que.push({0,0});
   while(!que.empty()){
       P pos=que.front();
       que.pop();
       ll x=pos.first;
       ll y=pos.second;
       for (int i = 0; i < 4; ++i) {
           if(x+dx[i]<0||x+dx[i]>=w)continue;
           if(y+dy[i]<0||y+dy[i]>=h)continue;
           ll tox=x+dx[i];
           ll toy=y+dy[i];
           ll pre=d[y][x];
           if(s[toy][tox]=='#')continue;
           if(d[toy][tox]>pre+1){
               que.push({tox,toy});
               d[toy][tox]=pre+1;
           }
       }
   }
   h--;w--;
   if(d[h][w]==INF)cout <<-1<<endl;
   else {
    cout <<white-d[h][w]-1<<endl;
   }
   return 0;
}