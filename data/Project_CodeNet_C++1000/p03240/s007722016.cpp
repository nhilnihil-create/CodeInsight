#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define int long long
#define mp make_pair
#define pb push_back
#define _GLIBCXX_DEBUG
const int INF=1e15;
typedef pair<int,int> P;

int dist(P A,P B){
    return abs(A.first-B.first)+abs(A.second-B.second);
}

signed main(){
  	int N;cin>>N;
    int ansx,ansy,ansh;
    vector<pair<P,int>>vec(N);
    REP(i,N){
        int x,y,h;cin>>x>>y>>h;
        P d=mp(x,y);
        vec[i]=mp(d,h);
    }
  	bool fin=false;
    REP(i,101){
        REP(j,101){
            P place=mp(i,j);
            int ifh=0;
            bool ok=true;
            REP(k,N){
              	if(ifh==0&&vec[k].second!=0)ifh=vec[k].second+dist(place,vec[k].first);
                else{
                    if((vec[k].second==0&&dist(place,vec[k].first)<ifh)||(vec[k].second!=0&&ifh!=vec[k].second+dist(place,vec[k].first)))ok=false;
                }
                if(k==N-1&&ok){
                  	ansx=place.first;
                    ansy=place.second;
                    ansh=ifh;
                }
            }
        }
    }
    cout<<ansx<<" "<<ansy<<" "<<ansh<<endl;
}