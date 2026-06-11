#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(int)(n); i++)

using namespace std;
typedef long long LL;
typedef pair<int,int> P;
const int INF=1e9;

int ans, N;
int A[3];
vector<int> l(10);
int sep[10];
void dfs(int size){
	if(size==N){
		int res=0;
		int sum[4]={0}, num[4]={0};
		rep(i,N){
			sum[sep[i]]+=l[i];
			num[sep[i]]++;
		}
		rep(i,3) if(num[i]==0) return;
		rep(i,3){
			res+=abs(A[i]-sum[i]);
			res+=10*(num[i]-1);
		}
		ans=min(ans,res);
		return;
	}
	rep(i,4){
		sep[size]=i;
		dfs(size+1);
	}
}

int main(){
	cin >> N;
	rep(i,3) cin >> A[i];
	rep(i,N) cin >> l[i];
	ans=INF;
	rep(i,N) sep[i]=0;
	dfs(0);
	cout << ans << endl;

	return 0;
}