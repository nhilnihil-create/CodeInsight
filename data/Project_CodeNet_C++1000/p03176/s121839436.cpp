#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define MAX 100005
#define ff first
#define ss second
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
const int MAXN = 2e5+5;
ll t[4*MAXN];
void build(int v, int tl, int tr){
	if(tl==tr)
		t[v]=0LL;
	else{
		int tm = (tl+tr)/2;
		build(v*2,tl,tm);
		build(v*2+1,tm+1,tr);
		//depende la operación a realizar.
		t[v]=max(t[v*2],t[v*2+1]);
	}
}
ll get(int v, int tl, int tr, int l, int r){
	if(l>r)
		//retornar valor neutro de la opéración.
		return 0;
	if(tl==l&&tr==r)
		return t[v];		
	int tm = (tl+tr)/2;
	return max(get(v*2,tl,tm,l,min(r,tm)),get(v*2+1,tm+1,tr,max(tm+1,l),r));
		
}
void update(int v,int tl, int tr, int pos, ll new_val){
	if(tl==tr)
		t[v]=new_val;
	else{
		int tm  = (tl+tr)/2;
		if(pos<=tm)
			update(v*2,tl,tm,pos,new_val);
		else
			update(v*2+1,tm+1,tr,pos,new_val);
		t[v]=max(t[v*2],t[v*2+1]);
	}
}

int n,h[MAXN];
ll dp[MAXN],a[MAXN];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i =0; i<n; ++i){
        cin>>h[i];
    }
    for(int i =0; i<n; ++i){
        cin>>a[i];
    }
    ll ans =0;
    build(1,0,n);
    for(int i =0; i<n; ++i){
        dp[i] = get(1,0,n,0,h[i]-1);
        //error(i,dp[i]);
        dp[i]+=a[i];
        //error(i,dp[i]);
        update(1, 0, n, h[i], dp[i]);
        ans = max(ans,dp[i]);
    }
    cout<<ans<<"\n";
}