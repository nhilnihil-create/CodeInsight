//       Author: Mostafa Mounir Shehab
 
#include <bits/stdc++.h>
using namespace std;
 
#define PI  acos(-1)
#define EPS (1e-10)
#define endl "\n"
#define SZ(v) (int)(v.size())
#define IO ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL), cerr.tie(NULL);
typedef long long ll;
typedef long double ld;
 
 
 
ll MOD=1e9 + 7;
ll OO=1e9 + 7;
const int N=1e5 + 10,M = 2750131 + 1;
int arr[N];
int vis[N];

int n,m,k,T,lvl,comp;
int a,b,c;

int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0}; 


bool Solve(){
	
	for(int i=0;i<N;++i){
		bool flage = false;
		for(int j=0;j<n && arr[j]<=i;++j)
			flage |= !vis[i-arr[j]];
			
		vis[i] = flage;
	}
	
	return vis[k];
}



int main(){
	
	//freopen("algoritm.in","r",stdin);
//	freopen("algoritm.out","w",stdout);
	IO
	cin>>n>>k;
	for(int i=0;i<n;++i)
		cin>>arr[i];
	sort(arr,arr+n);
	
	cout<<(Solve() ? "First" : "Second")<<endl;
	
	return 0;
}