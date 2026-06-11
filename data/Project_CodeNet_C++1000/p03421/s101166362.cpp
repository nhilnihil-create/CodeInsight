#include <iostream>
#include <vector>

using namespace std;

vector<int> solve(int N, int A, int B){
	vector<int> res;
	for(int i=0;i<A;i++) res.push_back(N-A+1+i);
	long long rest = N-A;
	long long block = B-1;
	if(block > rest) return vector<int>(1, -1);
	if(rest > A * block) return vector<int>(1, -1);
	long long a = rest - block;
	for(int i=0;i<block;i++){
		int back = min(A - 1LL, a);
		for(int j=rest-back;j<=rest;j++) res.push_back(j);
		rest -= back + 1;
		a -= back;
	}
	return res;
}

int main(){
	int N, A, B;
	while(cin >> N >> A >> B){
		vector<int> v = solve(N, A, B);
		cout << v[0];
		for(int i=1;i<v.size();i++) cout << " " << v[i];
		cout << endl;
	}
}
