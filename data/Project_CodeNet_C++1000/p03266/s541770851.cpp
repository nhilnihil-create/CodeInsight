// C - Triangular Relationship
#include <bits/stdc++.h>
using namespace std;

int main(){
	int N,K; cin>>N>>K;
	int f = N/K;
	long long ans = (long long)f*f*f;
	if(K%2 == 0){
		int h = N/(K/2) - f;
		ans += (long long)h*h*h;
	}
	cout<< ans <<endl;
}
