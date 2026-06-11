#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <algorithm>
#include <queue>
using namespace std;
int N,K;
int V[51];
int ans=0;
int ma=-1000000000;
int main(){
	cin >> N >> K;
	for(int i=1;i<=N;i++)cin >> V[i];
	int R = min(N,K);
	for(int i=0;i<=R;i++){
		for(int j=0;i+j<=R;j++){
			ans=0;
			priority_queue<int> q;
			for(int k=0;k<i;k++)q.push(-1*V[k+1]);
			for(int k=0;k<j;k++)q.push(-1*V[N-k]);
			int x=K-i-j;
			while(!q.empty()){
				if(x<=0 || q.top()<=0)break;
				x--;
				q.pop();
			}
			while(!q.empty()){
				ans=ans+(-1)*q.top();
				q.pop();
			}
			//printf("%d %d %d\n",i,j,ans);
			ma=max(ma,ans);
		}
	}
	cout << ma << endl;
	return 0;
}