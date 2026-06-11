//高知能系Vtuberの高井茅乃です。
//Twitter: https://twitter.com/takaichino
//YouTube: https://www.youtube.com/channel/UCTOxnI3eOI_o1HRgzq-LEZw

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define INF 1999999999
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define MODA 1000000007 

int main() {
	int ans = 0;
	int tmp;
	
	//エラトステネスの篩でP_max以下の素数vector primeをつくる
	bool *pr;
	int P_max = 1000000; //10^6くらいまでが現実的か
	pr = (bool*)malloc(sizeof(bool) * P_max);
	REP(i, P_max) {
		pr[i] = i;
	}
	REP(i, P_max + 1) pr[i] = true;
	pr[0] = false;
	pr[1] = false;
	for(int i = 2; i * i <= P_max; i++){ 
		if(pr[i] == true){
			for(int j = 2 * i; j <= P_max; j+=i){
				pr[j] = false;
			}
		}
	}
	vector<int> prime;
	for(int i = 2; i <= P_max; i++){
		if(pr[i]) prime.push_back(i);
	}
	//
	int n;
	cin >> n;
	vector <int> answer;
	REP(i, prime.size()){
		if(prime[i] % 5 == 1)answer.push_back(prime[i]);
	}
	REP(i, n) cout << answer[i] << " ";
	cout << endl;
}