
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define all(v) v.begin(), v.end()
#define F first
#define S second
#define INF 1000000000000
#define MOD 10000007
#define PI 3.14159265359
#define dij priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>
typedef long long ll;
//
int main(){
    int d,g;cin>>d>>g;
    vector<pair<int,int>> v;
    rep(i,d){
        int a,b;cin>>a>>b;
        v.push_back(make_pair(a,b));
    }
    //reverse(all(v));
    ll mi=INF;
    rep(i,1<<d){
        ll score=0,times=0;
        int mask=1;
        vector<bool> flag(d,false);
        //vector<pair<int,int>> vv=v;
        rep(j,d){
            if(i&mask<<j){
                times+=v[j].F;
                score+=v[j].S+100*(j+1)*v[j].F;
                flag[j]=true;  
            }
        }
        //cout<<times<<" "<<score<<endl;
        if(score>=g){
            mi=min(mi,times);
        }else{
            for(int k=d-1;k>=0;k--){
                if(!flag[k]){
                    //int z=v[k].F;
                    rep(a,v[k].F){
                        times++;
                        score+=100*(k+1);
                        if(score>=g)break;
                    }
                }
                if(score>=g)break;
            }
            mi=min(mi,times);
        }
        //cout<<times<<endl;
    }
    cout<<mi<<endl;
}