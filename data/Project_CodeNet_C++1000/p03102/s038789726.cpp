/* 競プロ用のテンプレ
 * SKMT
 * 作成日   2020年09月06日  15:46
 * ファイル名    ABC121_b.cpp
 */
#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)

int main(int argc, char const* argv[]){
	int N,M,C;
	cin >> N>>M>>C;
	vector<int> b(M);
	vector<vector<int>> a(N,vector<int>(M));
	rep(i,M) cin >> b.at(i);
	rep(i,N){
		rep(j,M){
			int temp;
		cin >> temp;
		a.at(i).at(j)=temp;
		}
	}
	int cnt=0;
	long sum=C;
	rep(i,N){
		rep(j,M){
			sum+=a.at(i).at(j) * b.at(j);
		}
		if(sum > 0) cnt++;
		sum=C;
	}
	cout << cnt << endl;
	return 0;
}
