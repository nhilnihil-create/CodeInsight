#include<bits/stdc++.h>
using namespace std;
int n;
int x[105];
int y[105];
int h[105];
int solve(int yy,int xx){
	int ret = -1;
	int maxheight = numeric_limits<int>::max();
	for(int i=0; i<n; i++){
		int delta = abs(xx-x[i])+abs(yy-y[i]);
		if(h[i]==0){
			//아무리 커봐야 delta까지만 가능  
			if(maxheight>delta) maxheight = delta;
			if(ret!=-1 && maxheight<ret) return -1;
		}
		else{
			int fix = delta+h[i];
			if(ret==-1) ret = fix;
			else if(ret!=fix) return -1;
			
			if(ret>maxheight) return -1;
		}
	}
	if(ret==-1) return maxheight;
	else return ret;
}
int main(){
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>x[i]>>y[i]>>h[i];
	}
	for(int i=0; i<=100; i++){
		for(int j=0; j<=100; j++){
			int height = solve(i,j);
			if(height!=-1){
				cout<<j<<" "<<i<<" "<<height<<'\n';
				return 0;
			}
		}
	}
}