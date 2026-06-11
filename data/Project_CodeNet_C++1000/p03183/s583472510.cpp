#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<vll> vvll;
typedef vector<ld> vld;
typedef map<ll,ll> mpll;
typedef set<ll> setll;
typedef multiset<ll> msetll;

#define F first
#define S second
#define pb push_back
#define mp make_pair

const ll mod = 1e9 + 7;
const ll inf = 99999999999999999;
ll n;
struct node{
	ll w;
	ll s;
	ll v;
};
vector<node> v;
ll memo[1001][10001][2];

ll func(int i,ll s1,int cc){
	if(i==n-1){
		if(v[i].w<=s1 || cc==0) 
			return v[i].v;
		else return 0;
	}

	if(memo[i][s1][cc]!=-1) return memo[i][s1][cc];
	ll ma=-1;
	if(cc==1){
		if(v[i].w<=s1){
			ma = max(ma,v[i].v + func(i+1,min(s1-v[i].w,v[i].s),1));
		}
		ma = max(ma,func(i+1,s1,cc));
	}
	else
	{
		ma = max(v[i].v + func(i+1,v[i].s,1),func(i+1,s1,0));
	}
	return memo[i][s1][cc]=ma;
}


int main()
{

	ios_base::sync_with_stdio(false);
    	cin.tie(NULL);
	#ifdef DEBUG_
		freopen("input.txt","r",stdin);
	#endif
	
	cout.setf(ios::fixed), cout.precision(20);

	cin >> n;
	v.resize(n);
	for(int i=0;i<n;i++){
		cin >> v[i].w >> v[i].s >> v[i].v;
	}
	auto cmp = [](node n1,node n2){
		return n1.w + n1.s > n2.w + n2.s;
	};
	sort(v.begin(),v.end(),cmp);
	// for(auto xx : v){
	// 	cout<<xx.w<<" "<<xx.s<<" "<<xx.v<<"\n";
	// }
	for(int i=0;i<=1000;i++){
		for(int j=0;j<=10000;j++)
		{
			memo[i][j][0]=-1;
			memo[i][j][1]=-1;
		}
	}
	cout<<func(0,0,0)<<"\n";

	return 0;
}

