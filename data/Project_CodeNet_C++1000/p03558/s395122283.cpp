#include <bits/stdc++.h>
using namespace std;

int K;
vector<int> n(100000,100000);
deque<int> deq;

int BFS(){
	while(!deq.empty()){
		int f=deq.front();
		deq.pop_front();
		if(f==0)return n[0];
		if(n[f]<n[(f*10)%K]){
			n[(f*10)%K]=n[f];
			deq.push_front((f*10)%K);
		}
		if(n[f]+1<n[(f+1)%K]){
			n[(f+1)%K]=n[f]+1;
			deq.push_back((f+1)%K);
		}
	}
}

int main(){
	cin >> K;
	deq.push_back(1);
	n[1]=1;
	cout << BFS() << endl;
	return 0;
}