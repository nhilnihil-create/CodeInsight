//高知能系Vtuberの高井茅乃です。
//Twitter: https://twitter.com/takaichino
//YouTube: https://www.youtube.com/channel/UCTOxnI3eOI_o1HRgzq-LEZw

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define INTINF 1999999999
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define MODA 1000000007 

int main() {
	int ans = 0;
	int tmp;
	int n;
	cin >> n;

	//エラトステネスの篩でP_max以下の素数vector primeをつくる
	bool *pr;
	int P_max = 100; //10^6くらいまでが現実的か
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

	//整数Xの素因数分解の結果をmapで返す。上のvector primeはもちろんいる
	map<int, int> prf;
	REP1(j,n){
		int X = j;
		int diving = X; //これをどんどん割っていく。dividingが正しい
		for(int i = 0; diving > 1 && prime[i] * prime[i] <= X; i++){
			while (diving % prime[i] == 0)
			{
				diving /= prime[i];
				prf[prime[i]]++;
			}
		}
		if(diving > 1)prf[diving]++;
	}

	for(auto iti = prf.begin(); iti != prf.end(); iti++){
		if(iti->second >= 74) ans++;
		for(auto itj = next(iti, 1); itj != prf.end(); itj++){
			if(iti->second >= 24 && itj->second >= 2) ans++;
			if(iti->second >= 2 && itj->second >= 24) ans++;
			if(iti->second >= 14 && itj->second >= 4) ans++;
			if(iti->second >= 4 && itj->second >= 14) ans++;
			for(auto itk = next(itj, 1); itk != prf.end(); itk++){
				if(iti->second >= 4 && itj->second >= 4 && itk->second >= 2) ans++;
				if(iti->second >= 4 && itj->second >= 2 && itk->second >= 4) ans++;
				if(iti->second >= 2 && itj->second >= 4 && itk->second >= 4) ans++;
			}
		}		
	}

	cout << ans << endl;
}