#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

vector<int> C[1<<18];
int N,A[1<<18],R[1<<18];

int main()
{
	scanf ("%d",&N);
	for (int i=0;i<(1<<N);i++){
		scanf ("%d",&A[i]);

		set<int> chk;
		chk.insert(i);
		for (int j=0;j<N;j++) if (i & (1 << j)){
			for (auto x : C[i-(1<<j)]) chk.insert(x);
		}

		C[i] = vector<int>(chk.begin(),chk.end());
		sort(C[i].begin(),C[i].end(),[](const int &a, const int &b){return A[a] > A[b];});
		if (C[i].size() > 2) C[i].resize(2);
	}

	for (int i=1;i<(1<<N);i++){
		R[i] = A[C[i][0]] + A[C[i][1]];
		if (R[i] < R[i-1])
			R[i] = R[i-1];

		printf ("%d\n",R[i]);
	}

	return 0;
}