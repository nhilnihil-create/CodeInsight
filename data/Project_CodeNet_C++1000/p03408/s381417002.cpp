#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=b;i--)
#define ALL(x) x.begin(),x.end()
#define SIZE(x) ll(x.size())

#define INF 1000000000000 //10^12
#define MOD 1000000007 //10^9+7:合同式の法
 
int main(){
    ll n,m;
    cin >> n;
    
    map<string,int> sn;
    REP(i,n){
        string tmp;
        cin >> tmp;
        sn[tmp]++;
    }

    cin >> m;
    map<string,int> tm;
    REP(i,m){
        string tmp;
        cin >> tmp;
        tm[tmp]++;
    }

    ll MAX = -100000;
    ll count = 0;
    for(auto itr=sn.begin(); itr!=sn.end(); itr++){
        string key = itr->first;
        ll val = sn[key] - tm[key];
        MAX = max(MAX,val);
        count++;
    }
    if(MAX<0){
        MAX = 0;
    }
    cout << MAX << endl;
    return 0;
}