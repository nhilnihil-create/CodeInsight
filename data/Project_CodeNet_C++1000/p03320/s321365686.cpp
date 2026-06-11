#include<bits/stdc++.h>
using namespace std;

long long K;

double cal(long long num){
	long long tmp = num;
	double dig = 0;
	while(tmp){
		dig += tmp%10;
		tmp /= 10;
	}
	return num/dig;
}

int main(){
	cin >> K;

	set<long long>cand;
	for(long long i = 1; i < 10; i++)
		cand.insert(i);
	for(long long i = 0; i < 13; i++){
		for(long long x = 0; x < 10; x++){
			for(long long y = 0; y < 10; y++){
				for(long long z = 0; z < 10; z++){
					long long tmp = 100 * x + 10 * y + z;
					for(long long k = 0; k < i; k++){
						tmp *= 10;
						tmp += 9;
					}
					cand.insert(tmp);
				}
			}
		}
	}
	cand.erase(0);

	vector<long long> vec;
	for(auto t: cand)
		vec.push_back(t);

	
	for(long long i = 0; i < vec.size() && K > 0; i++){
		bool ok = true;
		for(long long j = i + 1; j < vec.size() && j < i + 1000; j++){
			if(cal(vec[i]) > cal(vec[j]))
				ok = false;
		}
		if(ok){
			cout << vec[i] << endl;
			K--;
		}
	}

	/*
	if(K <= 9){
		for(long long i = 1; i <= K; i++){
			cout << i << endl;
		}
		return 0;
	}
	for(long long i = 1; i <= 9; i++){
		cout << i << endl;
	}
	K-=9;
	for(long long i = 1; i <= K; i++){
		cout << i << 9 << endl;
	}
	*/
}