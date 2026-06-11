#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <functional>
#include <queue>
#include <unordered_set>
#include <climits>
#include <set>
#include <list>
#include <cmath>
#include <map>

using namespace std;
typedef long long ll;

int main()
{
	ll N, M, Q;
	static ll L[200000];
	static ll R[200000];
	static ll p[200000];
	static ll q[200000];
	cin >> N >> M >> Q;
	for(int i = 0; i < M; i++){
		cin >> L[i] >> R[i];
	}
	for(int i = 0; i < Q; i++){
		cin >> p[i] >> q[i];
	}
	
	ll Section[502][502];
	ll SectionSum[502][502];
	for(int i = 0; i <= N+1; i++){
		for(int j = 0; j <= N+1; j++){
			Section[i][j] = 0;
			SectionSum[i][j] = 0;
		}
	}
	
	for(int i = 0; i < M; i++){
		Section[L[i]][R[i]]++;
	}
	
	for(int i = 0; i <= N+1; i++){
		for(int j = 1; j <= N+1; j++){
			SectionSum[i][j] = SectionSum[i][j-1] + Section[i][j];
		}
	}
	
	// 計算量：O(Q*N)
	for(int query = 0; query < Q; query++){
		ll ans = 0;
		for(int i = p[query]; i <= q[query]; i++){
			// i からスタートして、i〜q[query]までの区間で終わる列車の総和 をi=p[query]〜q[query]まで足す
			ans += SectionSum[i][q[query]] - SectionSum[i][i-1];
		}
		cout << ans << endl;
	}
	
	return 0;
}