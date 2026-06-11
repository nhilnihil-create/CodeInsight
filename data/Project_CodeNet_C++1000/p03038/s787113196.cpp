#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

ll N, M;

int main(){
	cin >> N >> M;
	
	vector<int> A(N);
	
	for ( int i = 0; i < N; i++ ){
		cin >> A[i];
	}
	sort(A.begin(),A.end()); // Aが小さい方から処理する
	
	vector<pii> BC(M);
	for ( int i = 0; i < M; i++ ){
		cin >> BC[i].first >> BC[i].second;
	}
	sort(BC.begin(),BC.end(),[](const pii &l, const pii &r){return l.second > r.second;}); // Cが大きいものから処理する
	
	int l = 0;
	for ( int i = 0; i < M; i++ ){
		while ( l < N && A[l] < BC[i].second && BC[i].first != 0 ){
			A[l] = BC[i].second;
			BC[i].first--;
			l++;
		}
	}
	
	ll sum = 0;
	for ( int i = 0; i < N; i++ )
		sum += A[i];
	cout << sum << endl;
	
	return 0;
}

