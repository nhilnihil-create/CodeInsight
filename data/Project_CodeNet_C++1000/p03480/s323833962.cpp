// D - Wide Flip
#include <bits/stdc++.h>
using namespace std;

int main(){
	string S; cin>> S;
	int K = S.size();
	for(int N=K, i=1; i<N; ++i)
		if(S[i-1] != S[i]) K = min(K, max(i, N-i));
	cout<< K <<endl;
}