/*"Everything in the universe is balanced. Every disappointment
   you face in life will be balanced by something good for you!
                Keep going, never give up."            */

#include "bits/stdc++.h"
using namespace std;

#define ll long long
const ll N=1e6+9;
const ll mod=1e9+7;

ll a[N];

void solve()
{    
    ll n, m ;
    cin >> n >> m;
    vector<int> v[n+1], parent(n+1,0) ;
    for(int i=0; i<m; i++){
    	int l, r; 
    	cin >> l >> r ;
    	v[l].push_back(r);
    	parent[r]++;
    }

    queue<pair<int,int>> q; 
    for(int i=1; i<=n; i++){
    	if(!parent[i])q.push({i,0});
    }
    int maxm = 0 ;

    while(!q.empty()){
    	auto it = q.front();q.pop();
    	//cout<<it.first<< " "<<it.second<<"\n";
    	maxm = max(maxm , it.second);
    	for(auto itt: v[it.first]){
    		parent[itt]--;
    		if(parent[itt]==0){
    			q.push({itt,it.second+1}) ;
    		}
    	}
    }
    cout<<maxm;

}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll t=1;
    //pre();
    //cin>>t;
    while(t--)
    {
      solve();
    }  
}


// Xorawar