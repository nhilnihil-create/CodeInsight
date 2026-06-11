#include<iostream>
#include<queue>
#include<vector>
using namespace std;
long long int a[100000], b[100000];
long long int sima[100001];
long long int fuben[100001];
long long int group[100001];
vector<int> graph[100001];
int main() {

	long long int n, m;
	cin >> n >> m;
	int i,j,k;
	for (i = 0; i < m; i++) {
		cin >> a[i] >> b[i];

	}
	for (i = 0; i < n; i++) {
		sima[i + 1] = i + 1;
		group[i + 1] = 1;
	}
	//各島のグループを設定した．
	//
	long long int counter = n * (n - 1) / 2;
	fuben[m] = n * (n - 1) / 2;
	queue<int> conection;
	for (i = m - 1; i >= 0; i--) {
		//橋を一本ずつ落としていく問題から，橋を一本ずつつなげていく問題に変える。

		if (sima[a[i]] == sima[b[i]]) {
			//このとき不便さは変わらず
			fuben[i] = fuben[i + 1];
			//cout << fuben[i] << endl;
		}
		else {
			//大きい方の島に統合
			fuben[i] = fuben[i + 1] - group[sima[a[i]]] * group[sima[b[i]]];
			//cout << fuben[i] << endl;
			if (group[sima[a[i]]] > group[sima[b[i]]]) {

 				//b[i]からたどれるすべての島をsima[a[i]]にする．
				group[sima[a[i]]] = group[sima[a[i]]] + group[sima[b[i]]];
				group[sima[b[i]]] = 0;
				sima[b[i]] = sima[a[i]];
				conection.push(b[i]);
				while (conection.size()) {
					j = conection.front(); conection.pop();
					for (k = 0; k < graph[j].size(); k++) {
						if (sima[graph[j][k]] != sima[a[i]]) {
							sima[graph[j][k]] = sima[a[i]];
							conection.push(graph[j][k]);
						}
					}
				}

				
				//cout << sima[a[i]] << ' ' << group[sima[a[i]]] << endl;
				
				
			}
			else {

				//a[i]からたどれるすべての島をsima[b[i]]にする．
				group[sima[b[i]]] = group[sima[b[i]]] + group[sima[a[i]]];

				group[sima[a[i]]] = 0;
				sima[a[i]] = sima[b[i]];
				conection.push(a[i]);
				while (conection.size()) {
					j = conection.front(); conection.pop();
					for (k = 0; k < graph[j].size(); k++) {
						if (sima[graph[j][k]] != sima[b[i]]) {
							sima[graph[j][k]] = sima[b[i]];
							conection.push(graph[j][k]);
						}
					}
				}

				//cout << sima[b[i]] << ' ' << group[sima[b[i]]] << endl;
				

			}
			//cout << endl;
			//for (j = 1; j <= n; j++) {
			//	cout << j << ' ' << sima[j] << endl;
			//}cout << endl;
			//for (j = 1; j <= n; j++) {
			//	cout << j << ' ' << group[j] << endl;
			//}
		}
		graph[a[i]].push_back(b[i]);
		graph[b[i]].push_back(a[i]);
		//a[i]とb[i]を接続

	}
	for (i = 1; i <= m; i++) {
		cout << fuben[i]  << endl;
	}
	return 0;

}