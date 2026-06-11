#pragma GCC optimize "-O3"
#include <bits/stdc++.h>
using namespace std;
#define LSOne(S) (S & (-S))
#define ll long long
#define two pair<int,int>
#define twol pair<ll,ll>
#define four pair<two,two>
#define pb push_back
#define mk make_pair
#define INF 1000000000000000000
#define P 1000000007
#define lmax 1000000000
#define nn 1000003
#define ff first.first
#define fs first.second
#define sf second.first
#define ss second.second
#define f first
#define s second
#define vi vector<int>
#define vll vector<ll>
#define vtwo vector<two>
#define ALL(container) (container).begin(), (container).end()
#define sz(container) (int)(container.size())
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define mid(a,b) (a+b>>1)
#define minN 0
#define maxN 10000000
#define na(x) ((x)<P?(x):(x)-P)
#define ab(a) (-(a)<(a)?(a):-(a))
#define FAST std::ios::sync_with_stdio(false)
#define xRand mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define rnd rng
#define IT iterator
inline int in(){
	int x=0,w=1;char ch=getchar();
	while ((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
	if (ch=='-') w=0,ch=getchar();
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return w?x:-x;
}
//---------------------------------------------------------------
//---------------------------------------------------------------
//---------------------------------------------------------------
//---------------------------------------------------------------
int n,Q,ch,M[3],ans;
char c[200004],a[200004],s[200004];
int check(int ind){
	for(int i=0;i<Q;i++)
		if(c[i]!=s[ind])continue;else
		if(a[i]=='L')ind--;
		else 		 ind++;
	if(ind>=n)return 2;
	if(ind<0)return 1;
	return 0;
}
void solve(){
	int l=-1,r=n;
	while(r-l>1){
		int mid=(l+r)/2;
		ch=check(mid);
//		cout<<mid<<" "<<ch<<endl;
		if(ch==2)r=mid;
		else l=mid;
	}
	if(check(r)!=2)r++;
	M[2]=r;
	l=-1,r=n;
	while(r-l>1){
		int mid=(l+r)/2;
		ch=check(mid);
//		cout<<mid<<" "<<ch<<endl;
		if(ch==1)l=mid;
		else r=mid;
	}
	if(check(r)!=1)r--;
	M[1]=r;
}
void read(){
	cin>>n>>Q;
	for(int i=0;i<n;i++)cin>>s[i];
	for(int i=0;i<Q;i++)
		cin>>c[i]>>a[i];
}
void print(){
	ans=1+(M[2]-1)-(M[1]+1);
//	cout<<M[2]<<" "<<M[1]<<endl;
	cout<<ans<<endl;
}
int main(){FAST;xRand;
read();
//check(2);
solve();
print();
}
/*

                   *         *
                  * *       * *
                 *   *     *   *
                *     *   *     *
                 *   *   * *   *
                  *   *   *   *
                   *   * *   *
                     *  *   *
					   *  *


*/




