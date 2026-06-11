#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
using Graph = vector<vector<int>>;
int main(){
	int N;
	cin>>N;
	int V=0;
	int E=0;
	vector<int> h(N);
	for(int i=0;i<N;i++){
		cin>>h[i];
		V+=h[i];
	}
	for(int i=1;i<N;i++){
		E+=min(h[i-1],h[i]);
	}
	cout<<V-E<<endl;
    return 0;
}