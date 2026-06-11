#include "bits/stdc++.h"
using namespace std;

int main() {
	int X, Y, Z, K;
	cin >> X >> Y >> Z >> K;
	vector<long long>A(X);
	vector<long long>B(Y);
	vector<long long>C(Z);
	for (int n = 0;n<X;++n) {
		cin >> A[n];
	}
	for (int n = 0; n < Y; ++n) {
		cin >> B[n];
	}
	for (int n = 0; n < Z; ++n) {
		cin >> C[n];
	}
	sort(A.begin(), A.end(), greater<long long>()); 
	sort(B.begin(), B.end(), greater<long long>());
	sort(C.begin(), C.end(), greater<long long>());
	using Data = pair<long long, tuple<int, int, int>>;
	priority_queue<Data>que;
	set<Data>st; 
	que.push(Data(A[0]+B[0]+C[0], make_tuple(0,0,0)));
	for (int n = 0;n<K;++n) {
		Data  d = que.top();
		que.pop();
		cout << d.first<<endl; 
		int i = get<0>(d.second); 
		int j = get<1>(d.second); 
		int k = get<2>(d.second);
		{
			if (X > i+1) {
				Data d0 = Data(A[i + 1] + B[j] + C[k], make_tuple(i + 1, j, k));
				if (!st.count(d0)) {
					st.insert(d0);
					que.push(d0);
				}
			}
		} 

		{	
			if (Y > j + 1) {
				Data d0 = Data(A[i] + B[j + 1] + C[k], make_tuple(i, j + 1, k));
				if (!st.count(d0)) {
					st.insert(d0);
					que.push(d0);
				}
			}
		}

		{	
			if (Z > k + 1) {
				Data d0 = Data(A[i] + B[j] + C[k + 1], make_tuple(i, j, k + 1));
				if (!st.count(d0)) {
					st.insert(d0);
					que.push(d0);
				}
			}
		}
	}
	return 0;
}