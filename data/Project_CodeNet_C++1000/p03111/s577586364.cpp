#include <bits/stdc++.h>
using namespace std;

int n,A,B,C;
int l[10];

int dfs(int i,int a,int b,int c){
	if(i==n){
		if(min({a,b,c})>0) return abs(A-a)+abs(B-b)+abs(C-c)-30;
		else return 1e9;
	}
	int res0=dfs(i+1,a,b,c);
	int res1=dfs(i+1,a+l[i],b,c)+10;
	int res2=dfs(i+1,a,b+l[i],c)+10;
	int res3=dfs(i+1,a,b,c+l[i])+10;
	return min({res0,res1,res2,res3});
}

int main() {
	cin >> n >> A >> B >> C;
	for(int i=0;i<n;i++) cin >> l[i];
	cout << dfs(0,0,0,0) << endl;
}
