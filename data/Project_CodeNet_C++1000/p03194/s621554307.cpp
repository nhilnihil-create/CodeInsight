#include<bits/stdc++.h>

using namespace std;

vector<long long> divisors(long long n) {
    vector<long long> res;
    for(long long i = 1; i * i <= n; ++i) {
        if(n % i != 0) continue;
        res.push_back(i);
        if(n / i == i) continue;
        res.push_back(n / i);
    }
    sort(res.begin(), res.end());
    return res;
}

int main(){
	long long N, P, ans = 0; cin >> N >> P;
	vector<long long> div = divisors(P);
	for(long long i = 0; i < (long long)div.size(); ++i){
		for(long long j = 0; j < (long long)div.size(); ++j){
			if((long long)pow(div[i], N) == P / div[j]) ans = max(ans, div[i]);
		}
	}
	cout << ans << endl;
}