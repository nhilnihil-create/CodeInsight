#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
deque<int> q;
int main(){
	ll m,k;
	cin>>m>>k;
	if(k>((1<<m)-1)){
		cout<<-1<<endl;
		return 0;
	}
	if(k==0){
		for(int i=0;i<(1<<m);i++){
			cout<<i<<" "<<i<<" ";
		}cout<<endl;
		return 0;
	}
	if(m==1){
		cout<<-1<<endl;
		return 0;
	}
	q.push_front(k);
	for(int i=0;i<(1<<m);i++){
		if(i==k) continue;
		q.push_front(i);
		q.push_back(i);
	}
	q.push_back(k);
	while(!q.empty()){
		cout<<q.front()<<" ";
		q.pop_front();
	}cout<<endl;
}