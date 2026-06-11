#include<bits/stdc++.h>
using namespace std;
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define uii             unordered_map<int,int>
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define w(x)            int x; cin>>x; while(x--)
void S_K_S()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}

int32_t main()
{
	S_K_S();
	int n;
	cin>>n;
	int a,b,c;
	cin>>a>>b>>c;
	int ta=a,tb=b,tc=c;
	int t1=a,t2=b,t3=c;
	for(int i=1;i<n;i++){
		cin>>a>>b>>c;
		ta=a+max(t2,t3);
		tb=b+max(t1,t3);
		tc=c+max(t1,t2);
		t1=ta;t2=tb;t3=tc;
	}
	// cout<<ta<<" "<<tb<<" "<<tc<<endl;
	cout<<max(ta,max(tb,tc));
}
