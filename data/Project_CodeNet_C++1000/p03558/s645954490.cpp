#include <iostream>
#include <deque>
using namespace std;

int K;
int inf = 1e8;
int d[100001];

int main(){
	cin >> K;
	for(int i=0;i<=K;i++){
		d[i] = inf;
	}
	d[1] = 1;
	deque<int> deq;
	deq.push_front(1);
	while(deq.size()){
		int p = deq.front();
		deq.pop_front();
		if(p==0) break;
		if(d[(p*10)%K] > d[p]){
			d[(p*10)%K] = d[p];
			deq.push_front((p*10)%K);
		}
		if(d[(p+1)%K] > d[p]+1){
			d[(p+1)%K] = d[p]+1;
			deq.push_back((p+1)%K);
		}
	}
	cout << d[0] << endl;
}