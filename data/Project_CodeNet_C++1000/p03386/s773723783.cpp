#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
	ios::sync_with_stdio(false);

	int A,B,K; cin>>A>>B>>K;
	set<int> sum;
	for(int i=A; i<A+K; i++){
		if(i>B) break;
		sum.insert(i);
	}

	for(int i=B; i>B-K; i--){
		if(i<A) break;
		sum.insert(i);
	}

	for(int x: sum){
		cout << x << endl;
	}
}
