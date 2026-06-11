#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
using namespace std;
typedef long long LL;
const int MR=1e6+10;

int f(int x,int b){
	int ans=0;
	while(x){
		ans+=x%b;
		x/=b;
	}
	return ans;
}

int main(){
	int N;
	cin>>N;
	int ans=N;
	for(int M=0;M<=N;M++){
		ans=min(ans,f(M,6)+f(N-M,9));
	}
	cout<<ans<<endl;
	return 0;
}