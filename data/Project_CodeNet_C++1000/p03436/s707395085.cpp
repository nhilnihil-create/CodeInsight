#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define REP(i,n) for (int64_t i=0; i<(n); ++i)
#define P pair<int,int>
using ll=int64_t;
using namespace std;
#define ketasuu(n) fixed<<setprecision(n)
#define btoe(p) p.begin(),p.end()
#define etob(p) p.rbegin(),p.rend()


const vector<P> dd={{-1,0},{0,1}, {1,0}, {0,-1}};

int main(){
    int h,w; cin>>h>>w;
    vector<string> s(h);
    rep(i,h) cin>>s[i];
    vector<vector<int>> p(h,vector<int>(w,0));
    deque<P> q;
    if(s[0][0]=='#'){
        cout<<-1<<endl;
        return 0;
    }
    q.push_back({0,0});
    while(!q.empty()){
        P now=q[0];
        int nowscore=p[now.first][now.second];
        q.pop_front();
        rep(i,4){
            P kari=now;
            kari.first+=dd[i].first; kari.second+=dd[i].second;
            if(0<=kari.first && kari.first<h && 0<=kari.second && kari.second<w && s[kari.first][kari.second]=='.' && p[kari.first][kari.second]==0){
                q.push_back(kari);
                p[kari.first][kari.second]=nowscore+1;
            }
        }
    }
    if(p[h-1][w-1]==0){
        cout<<-1<<endl;
        return 0;
    }
    int cnt=0;
    rep(i,h){
        rep(j,w){
            if(s[i][j]=='#') cnt++;
        }
    }
    cout<<h*w-p[h-1][w-1]-cnt-1 <<endl;
    return 0;
}