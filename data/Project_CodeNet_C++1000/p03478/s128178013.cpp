#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
	ios::sync_with_stdio(false);

	int N,A,B; cin>>N>>A>>B;

	int ct=0;
	for(int i=1; i<=N; i++){
		int num = i, sum=0;
		while(num>0){
			sum += num%10;
			num /= 10;
		}
		if(A<=sum && sum<=B){
			ct += i;
		}
	}

	cout << ct << endl;
}
