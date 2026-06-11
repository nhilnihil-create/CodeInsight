#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	int ans[M]={0};
	for (int i=0; i<N; i++){
	    int K;
	    cin >> K;
	    for (int i=0; i<K; i++){
	        int A;
	        cin >> A;
	        ans[A-1]++;
	    }
	}
	int count=0;
	for (int i=0; i<M; i++){
	    if (ans[i]==N) count++;
	}
	cout << count << endl;
}