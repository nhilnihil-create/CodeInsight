#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int N,K;
long long int ans=0;
int main(){
	cin >> N >> K;
	for(int b=1;b<=N;b++){
		int p=N/b;
		int r=N%b;
		ans+= p*(max(0,b-K));
		ans+= max(0,r-K+1);
		if(K==0)ans--;
	}
	cout << ans << endl;
	return 0;
}