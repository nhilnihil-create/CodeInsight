#include<iostream>
#include<deque>
#include<vector>
using namespace std;
int main(){
	int k;
	cin >> k;
	vector<int> used(k);
	deque<int> q;
	q.push_back(1);
	for(int i=0;i<k;i++) used[i]=1e9;
	used[1]=1;
	while(!q.empty()){
		int x=q.front();
		q.pop_front();
		int a=(x*10)%k,b=(x+1)%k;
		if(used[a]>used[x]){
			used[a]=used[x];
			q.push_front(a);
		}
		if(used[b]>used[x]+1){
			used[b]=used[x]+1;
			q.push_back(b);
		}
	}
	cout << used[0] << endl;
}
