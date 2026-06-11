#include <bits/stdc++.h>
using namespace std;
int main(){
	int N, T;cin>>N>>T;
	int a, b;
	priority_queue< pair<int,int> > pq;
	while(N--){
		cin>>a>>b;
		if(b <= T) pq.push({a,b});
	}
	if(pq.size() == 0){
		cout<<"TLE";
		return 0;
	}
	while(pq.size()>1)pq.pop();
	cout<<pq.top().first;
	return 0;
}