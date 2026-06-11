#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define REP(i,n) for (int64_t i=0; i<(n); ++i)
#define P pair<int,int>
using ll=int64_t;
using namespace std;
#define ketasuu(n) fixed<<setprecision(n)
#define btoe(p) p.begin(),p.end()
#define etob(p) p.rbegin(),p.rend()
#define chmax(x,y) x=max(x,y)



int main(){
    int h,w; cin>>h>>w;
    vector<string> s(h);
    rep(i,h) cin>>s[i];
    rep(i,h){
        rep(j,w){
            int a, b, cnt=0;
            if(s[i][j]=='#') continue;
            for(int dx=-1; dx<2; ++dx){
                for(int dy=-1; dy<2; ++dy){
                    if(dx==0 && dy==0){
                        continue;
                    }
                    a=i+dx; b=j+dy;
                    if(0<=a && a<h && 0<=b && b<w){
                        if(s[a][b]=='#') cnt++;
                    }
                }
            }
            s[i][j]=cnt+'0';
        }
    }
    rep(i,h){
        cout<<s[i]<<endl;
    }
}