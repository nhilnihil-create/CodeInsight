#include<bits/stdc++.h>
using namespace std;

long long N;
long long x[1005];
long long y[1005];

int main(){
	cin >> N;
	bool ok = true;
	for(long long i = 0; i < N; i++){
		cin >> x[i] >> y[i];
		if(i != 0){
			if((abs(x[0]) + abs(y[0]))%2 != (abs(x[i]) + abs(y[i]))%2){
				ok = false;
			}
		}
	}
	if(!ok){
		cout << -1 << endl;
		return 0;
	}

	vector<long long> arm;
	for(long long len = pow(2, 32);  len>=1; len/=2){
		arm.push_back(len);
	}
	if((abs(x[0]) + abs(y[0]))%2 == 0){ 
		arm.push_back(1);
	}

	cout << arm.size() << endl;
	for(long long i = 0; i < arm.size(); i++){
		cout << arm[i];
		if(i == arm.size() - 1){
			cout << endl;
		}else{
			cout << " ";
		}
	}
	for(long long i = 0; i < N; i++){
		long long tarx = x[i];
		long long tary = y[i];
		long long curx = 0;
		long long cury = 0;
		string ans = "";
		for(long long j = 0; j < arm.size(); j++){
			long long diffx = tarx - curx;
			long long diffy = tary - cury;
			if(abs(diffx) > abs(diffy)){
				if(diffx >= 0){
					ans+="R";
					curx += arm[j];
				}else{
					ans+="L";
					curx -= arm[j];
				}
			}else{
				if(diffy >= 0){
					ans+="U";
					cury += arm[j];
				}else{
					ans+="D";
					cury -= arm[j];
				}
			}
		}
		cout << ans << endl;
	}
}
