#include <bits/stdc++.h>
using namespace std;
#define rp(i,s,e) for(int i=(s);i<(e);++i)

int main(){
	string S; cin>> S;
	int N = S.size();
	int ans = N;
	rp(k, 1, N){
		if(S[k-1] != S[k]){
			ans = min(ans, max(k, N-k));
		}
	}
	cout<< ans <<endl;
}
