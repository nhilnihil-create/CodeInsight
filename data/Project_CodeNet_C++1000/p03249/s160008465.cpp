#include <iostream>
#include <fstream>
#include <cstdio>
#include <cassert>
#include <complex>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <numeric>
#include <sstream>
#include <ctime>
#include <cctype>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <deque>
#include <stack>
#include <memory.h>
using namespace std;
typedef long long ll;
#define mp make_pair
vector<pair<ll,int> > e;
map<ll,int> ret;
int n;
inline void die(){
    puts("-1");
    exit(0);
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        ll x;
        cin>>x;
        ret[x]=i;
        e.push_back(mp(x,i));
    }
    sort(e.begin(),e.end());
    reverse(e.begin(),e.end());
    ll x=e.back().first;
    vector<int> siz(n,1);
    vector<ll> dp(n,0);
    vector<pair<int,int> > ans;
    for(int i=0;i<e.size();i++){
        pair<ll,ll> c=e[i];
        if(c.first==x) continue;
        if(siz[c.second]*2>=n){
        	die();
		}
        ll need=c.first+2*siz[c.second]-n;
        if(!ret.count(need)){
        	die();
		}
        int par=ret[need];
        dp[par]+=dp[c.second]+siz[c.second];
        siz[par]+=siz[c.second];
        ans.push_back(mp(c.second+1,par+1));
    }
    if(dp[e.back().second]!=x){
    	die();
	}
    for(int i=0;i<ans.size();i++){
    	if(ans[i].first>ans[i].second){
    		swap(ans[i].first,ans[i].second);
		}
	}   
	sort(ans.begin(),ans.end());
	for(int i=0;i<ans.size();i++){
		cout<<ans[i].first<<" "<<ans[i].second<<endl;
	}
    return 0;
}
