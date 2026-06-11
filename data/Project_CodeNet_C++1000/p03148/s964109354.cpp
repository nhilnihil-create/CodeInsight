#include <iostream>
#include <algorithm>
#include <vector>
#include<string>
#include <set>
#include <map>
#include <queue>
#include <limits.h>
#include <bitset>
#include <cmath>

using namespace std;

#define rip(i, n, s) for (int i = (s);i < ( int )( n ); i++)
#define all(a) (a).begin(), (a).end()
typedef long long ll;
typedef pair<ll,pair<int,int>> P;

int main(){
    int n,k;
    cin >> n >> k;
    vector<P> da(n);
    map<int,P> ma;
    rip(i,n,0){
        cin >> da[i].second.first >> da[i].first;
        da[i].second.second=i;
        if(ma.count(da[i].second.first)){
            ma[da[i].second.first]=max(da[i],ma[da[i].second.first]);
        }
        else{
            ma[da[i].second.first]=da[i];
        }
    }
    vector<bool> top(n,true);
    for(auto i:ma){
        top[i.second.second.second]=false;
    }
    sort(all(da));
    reverse(all(da));
    priority_queue<P,vector<P>,greater<P>> pq;
    ll ans=0;
    int co=k;
    set<int> check;
    rip(i,k,0){
        ans+=da[i].first;
        pq.push(da[i]);
        if(!check.count(da[i].second.first)){
            check.insert(da[i].second.first);
            //top[da[i].second.second]=false;
        }
    }
    ll now=ans;
    ans+=(ll) check.size()*check.size();
    while(co<n){
        if(!top[da[co].second.second]){
            check.insert(da[co].second.first);
            while(!pq.empty()){
                P ju=pq.top();
                pq.pop();
                //cout << ju.second .second << endl;
                if(top[ju.second.second]){
                    now-=ju.first;
                    now+=da[co].first;
                    ll siz=check.size();
                    ans=max(ans,now+siz*siz);
                    //cout << now << endl;
                    break;
                }
            }
        }
        co++;
    }
    cout << ans << endl;
}