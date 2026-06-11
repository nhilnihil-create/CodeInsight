#include <bits/stdc++.h>
using namespace std;
 
vector<long long>vec;
 
int main() {
    int X, Y, Z, K;
	cin >> X >> Y >> Z >> K;
    vector<long long> A(X),B(Y),C(Z);
	for (int i=0; i<X; ++i) cin >> A[i]; sort(A.begin(), A.end(), greater<long long>());
	for (int i=0; i<Y; ++i) cin >> B[i]; sort(B.begin(), B.end(), greater<long long>());
	for (int i=0; i<Z; ++i) cin >> C[i]; sort(C.begin(), C.end(), greater<long long>());

    priority_queue<pair<long long, vector<int> > > pq;
    set<vector<int> > history;

    const int N = 3;

    long long init = A[0]+B[0]+C[0];
    pq.push(make_pair(init, vector<int>(N, 0)));
    history.insert(vector<int>(N, 0));

	for (int i = 0; i < K; ++i) {
        long long sum;
        vector<int> index;

        tie(sum, index) = pq.top(); pq.pop();
        cout << sum << endl;

        if(index[0] < X - 1) {
            vector<int> index1 = index;
            ++index1[0];
            if(history.find(index1) == history.end()){
                long long sum1 = sum - A[index[0]] + A[index1[0]];
                pq.push(make_pair(sum1, index1));
                history.insert(index1);
            }
        }
        if(index[1] < Y - 1) {
            vector<int> index1 = index;
            ++index1[1];
            if(history.find(index1) == history.end()){
                long long sum1 = sum - B[index[1]] + B[index1[1]];
                pq.push(make_pair(sum1, index1));
                history.insert(index1);
            }
        }
        if(index[2] < Z - 1) {
            vector<int> index1 = index;
            ++index1[2];
            if(history.find(index1) == history.end()){
                long long sum1 = sum - C[index[2]] + C[index1[2]];
                pq.push(make_pair(sum1, index1));
                history.insert(index1);
            }
        }
    }

	return 0;
}
