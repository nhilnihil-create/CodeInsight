#include<cmath>
#include<cstdio>
#include<cstring>
#include<vector>
#include<iostream>
#include<algorithm>
#define rep(i,l,r) for (int i=(l); i<=(r); i++)
typedef long long ll;
using namespace std;

const int N=1010;
int n,tot;
vector<int>V[N];

int main(){
	scanf("%d",&n); int k=sqrt(2*n)+1;
	if (k*(k-1)/2==n && 2*n%k==0){
		puts("Yes"); printf("%d\n",k);
		rep(i,1,k-1) rep(j,i+1,k) V[i].push_back(++tot),V[j].push_back(tot);
		rep(i,1,k){
			printf("%d ",2*n/k);
			rep(j,0,(int)V[i].size()-1) printf("%d ",V[i][j]);
			puts("");
		}
	}else puts("No");
	return 0;
}