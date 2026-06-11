#include <bits/stdc++.h>
using namespace std;


int main(){
	int N,H,W;cin>>N>>H>>W;
	int cnt = 0;
	for(int i=0;i<N;i++){
		int a,b;cin>>a>>b;
		if(a >= H && b >= W) cnt += 1;
	}
	cout<<cnt<<endl;
}