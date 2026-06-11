#include <bits/stdc++.h>
using namespace std;

int main(){
	long long n;
	string stones;
	getline(cin,stones,'\n');
	n = stones.length();
	long long cnt = 0;
	long long cntB = 0;
	for(long i=0;i<n;i++){
		if(stones[i]=='B'){
			cntB++;
		}else{
			cnt+=cntB;
		}
	}
	cout << cnt << endl;
}
