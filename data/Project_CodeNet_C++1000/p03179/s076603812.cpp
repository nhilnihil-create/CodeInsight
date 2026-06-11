#include<bits/stdc++.h>
#include <iomanip>
#define ll long long int
#define ld long double
#define IOS cin.tie(NULL);cout.tie(NULL)
#define f first
#define inf 100000000000000000
#define ii pair<ll,ll>
#define vi vector<ll>
#define vii vector<ii>
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define sc(i) scanf("%lld",&i);
#define s second
#define pb push_back
#define forn(i,n) for(int i=0;i<(int)n;i++)
using namespace std;
ll const mod=998244353;
ll gcdfun(ll a , ll b)
{
   if(b==0) return a;
   a%=b;
   return gcdfun(b,a);
}
// int arr1[1000109];
// set<ll> sieve;
// void sievefun(ll n){
//     for(ll i=2;i<=n;i++){
//         if(arr1[i]==0){
//             for(ll j=i*i;j<=n;j+=i){
//                 arr1[j]=1;
//             }
//         }
//     }
//     for(ll i=2;i<=n;i++){
//     	if(arr1[i]==0)sieve.insert(i);
//     }
// }
ll power(ll x, ll y,ll m) {
	ll temp;
	if( y == 0)
		return 1;
	temp = power(x, y/2,m)%m;
	if (y%2 == 0)
		return ((temp)*(temp))%m;
	else
		return (((x)%m)*((temp*temp)%m))%m;
}
// struct tt{
// 	ll val,cnt;
// };
// ll a[1000009]; 
// tt tree[5000009];
// ll num=1000000000;
// void build(int node,int start,int end){
// 	int mid=(start+end)/2;
// 	if(start==end){
// 		tree[node].val=a[start];
// 		tree[node].cnt=1;
// 		return ;
// 	}
// 	build(2*node,start,mid);
// 	build(2*node+1,mid+1,end);
// 	ll temp=gcdfun(tree[2*node].val,tree[2*node+1].val);
// 	tree[node].val=temp;
// 	if(temp==tree[2*node].val)tree[node].cnt+=tree[2*node].cnt;
// 	if(temp==tree[2*node+1].val)tree[node].cnt+=tree[2*node+1].cnt;
	
// }
// // void update(int node,int start,int end,int index,ll num){
// // 	int mid=(start+end)/2;
// // 	if(start==end){
// // 		tree[node]+=num;
// // 		return ;
// // 	}
// // 	if(start<=index&&index<=mid){
// // 		update(2*node,start,mid,index,num);
// // 	}
// // 	if(index>mid&&index<=end){
// // 		update(2*node+1,mid+1,end,index,num);
// // 	}
// // 	tree[node]=tree[2*node]+tree[2*node+1];
// // }
// tt query(int node,int start,int end,int l,int r){
// 	int mid=(start+end)/2;
// 	if(start>=l&&end<=r)return tree[node];
// 	if(start>r||end<l){
// 		tt temp={0,0};
// 		return temp;
// 	}
// 	tt L=query(2*node,start,mid,l,r);
// 	tt R=query(2*node+1,mid+1,end,l,r);
// 	tt temp;
// 	if(L.val==0)return R;
// 	if(R.val==0)return L;
// 	temp.cnt=0;
// 	temp.val=(gcdfun(L.val,R.val));
// 	if(temp.val==L.val)temp.cnt+=L.cnt;
// 	if(temp.val==R.val)temp.cnt+=R.cnt;
// 	return temp;
// }
ll dp[3009][3009];
ll m;
int main()
{	//sievefun(100000);
	// cout << fixed << setprecision(10);
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	ll T;
	// cin>>T;
	T=1;
	forn(_,T){
		ll n;
		cin>>n;
		m=1000000007;
		string s;
		cin>>s;
		forn(i,n){
			dp[0][i+1]=1;
		}
		forn(i,n-1){
			if(s[i]=='<'){
				for(int j=2;j<=i+2;j++){
					dp[i+1][j]=(dp[i+1][j-1]+dp[i][j-1])%m;
				}
			}else{
				for(int j=i+1;j>=1;j--){
					dp[i+1][j]=(dp[i][j]+dp[i+1][j+1])%m;
				}
			}
		}
		// for(int i=0;i<=n-1;i++){
		// 	for(int j=1;j<=n;j++)cout<<dp[i][j]<<" ";
		// 		cout<<"\n";	
		// }
		ll ans=0;
		forn(i,n)ans=(ans+dp[n-1][i+1])%m;
		cout<<ans<<"\n";
	}

}