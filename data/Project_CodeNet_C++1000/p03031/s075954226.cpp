#include <iostream>
#include <stdio.h>

#include <vector>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <climits>

using namespace std;


int main(){
	
	int n, m;
	
	cin >> n>> m;
	
	int k,pp;

	//以下がダメな理由を考えておくこと
	/*
	vector<vector<int> > arr(m, vector<int>(n));
	*/

	//以下がダメな理由を考えておくこと
	/*
	for (int i = 0; i < m; i++) {
		cin >> k;
		for (int j = 0; j < k; j++) {
			cin >> pp;
			arr[i][pp-1]++;
		}
	}
	*/

	vector<vector<int>> arr(m);

	for (int i = 0; i < m; i++) {
		cin >> k;
		for (int j = 0; j < k; j++) {
			cin >> pp; --pp;
			//cin >> pp;
			arr[i].push_back(pp);
		}
	}

	
	vector<int> p(m);

	for (int i = 0; i < m; i++) cin >> p[i];
	
	//bit全探索
	int ans = 0;	
	
	//ありうるパターンを列挙
	//pow→xのn乗（この場合は2の3乗）
	for (int i = 0; i < (1<<n); i++) {
		
		//判定部分
		bool ok = true;

		//Sw個数分探索
		//j→行を変化させている(電球ごと)
		for (int h = 0; h < m; h++) {

			int count = 0;

			for (int j : arr[h]) {

				if (i & (1 << j))count++;
			}
				/*
				//k→列を変化させている（同じ電球の中でのSwの変化）
				for (int k = 0; k < n; k++) {
					//各パターンでのbit列の対応づけ
					//該当の部分がある
					if (i& (1<<arr[j][k]))count++;
				}
				*/

				//条件判定開始
				//列ごとに1回でも以下に引っかかったらアウト
				//その後のSWでOKでもOKに戻すことがない

				if (p[h] != count % 2) {
					ok = false;
				}

			
		}
		//これは各ビット列ごとに実施
		//そのパターンで一度もfalseに引っかからなければ以下。
		if (ok) ans++;
	}

	cout << ans << endl;

	return 0;
}