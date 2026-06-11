#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vl vector<long long int>
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define all(x) x.begin(),x.end()
#define vi vector<int>
#define vb vector<bool>
#define vvl vector<vector<ll> >
#define vvi vector<vector<int> >
#define pl pair<ll,ll>
#define pb push_back
#define PI 3.14159265
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define fri(s,n) for(int i=s;i<n;i++)
#define frj(s,n) for(int j=s;j<n;j++)
#define T(i) int i=1;cin>>i;while(i--)
#define vsi vector<set<int> >
#define pii pair<int,int>
#define inf 1e9
#define vpii vector<pair<int,int> >


ll power(ll a,ll b){
    if(b==0)
        return 1;
    if(b&1)
        return a*power(a,b-1);
    ll temp=power(a,b/2);
    return temp*temp;
    }
bool mycompare(ll a,ll b){
    return a>b;
    }

void solve(int *height,int *beauty,int n){
	ll dp[n];//dp[i] will give me the maximum beaty we can get including flower i
  	map<ll,ll> m;
  	ll ans=beauty[0];
  	m[height[0]]=beauty[0];
  	dp[0]=beauty[0];
  	for(int i=1;i<n;i++){
    	int h=height[i],b=beauty[i];
      	dp[i]=b;
      	auto it=m.upper_bound(h);
      	if(it!=m.begin()){
        	it--;
          	dp[i]+=it->second;
        	}
      	it=m.upper_bound(height[i]);
      	while(it!=m.end() && it->second<=dp[i]){
        	auto temp=it;
          	temp++;
          	m.erase(it);
          	it=temp;
        }
        m[h]=dp[i];
        ans=max(ans,dp[i]);

    }

	cout<<ans;

	}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n;
  	cin>>n;
  	int height[n];
  	for(int i=0;i<n;i++)
      cin>>height[i];
  	int beauty[n];
  	for(int i=0;i<n;i++)
      cin>>beauty[i];
  	solve(height,beauty,n);


	}

