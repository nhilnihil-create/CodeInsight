#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int,int>P;

int main(){
	int n,h,w;cin>>n>>h>>w;
	int cnt=0;
	rep(i,n){
		int a,b;scanf("%d%d",&a,&b);
		if(a>=h&&b>=w)cnt++;
	}
	cout<<cnt<<endl;
}