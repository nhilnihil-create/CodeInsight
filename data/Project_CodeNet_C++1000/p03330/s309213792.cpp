#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>
#include <iomanip>
typedef long long int ll;
typedef long double ld;
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
const ll MOD=1000000007;
const ll MAX_N=500010;
const ll INF=999999999999;
int d[40][40];
int g[550][550];

bool comp(pair<ll,ll> p1,pair<ll,ll> p2){
    return p1.first<p2.first;
}

int main(){
    int n,c;
    cin>>n>>c;
    for(int i=1;i<=c;i++){
        for(int j=1;j<=c;j++){
            cin>>d[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>g[i][j];
        }
    }

    /*ll ans=INF;
    for(int zero=1;zero<=c;zero++){
        for(int one=1;one<=c;one++){
            if(one==zero) continue;
            for(int two=1;two<=c;two++){
                if(two==one || two==zero) continue;
                ll cc=0;
                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        if((i+1+j+1)%3==0){
                            cc+=d[g[i][j]][zero];
                        }else if((i+1+j+1)%3==1){
                            cc+=d[g[i][j]][one];
                        }else{
                            cc+=d[g[i][j]][two];
                        }
                    }
                }
                ans=min(cc,ans);
            }
        }
    }*/
    vector<pair<ll,ll> > zero; 
    vector<pair<ll,ll> > one; 
    vector<pair<ll,ll> > two; 
    for(int color=1;color<=c;color++){
        ll cc0=0;
        ll cc1=0;
        ll cc2=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if((i+1+j+1)%3==0) cc0+=d[g[i][j]][color];
                if((i+1+j+1)%3==1) cc1+=d[g[i][j]][color];
                if((i+1+j+1)%3==2) cc2+=d[g[i][j]][color];
            }         
        }
        zero.push_back(make_pair(cc0,color));
        one.push_back(make_pair(cc1,color));
        two.push_back(make_pair(cc2,color));
    }
    sort(zero.begin(),zero.end(),&comp);
    sort(one.begin(),one.end(),&comp);
    sort(two.begin(),two.end(),&comp);
    ll ans=INF;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                if(zero[i].second!=one[j].second && zero[i].second!=two[k].second && two[k].second!=one[j].second){
                    //cout<<i<<" "<<j<<" "<<k<<" "<<zero[i].first+one[j].first+two[k].first<<endl;
                    ans=min(ans,zero[i].first+one[j].first+two[k].first);
                }
            }
        }
    }
    cout<<ans<<endl;
}