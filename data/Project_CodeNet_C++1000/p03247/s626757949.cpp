#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int N; long long X[1010],Y[1010]; int P[1010];
char A[1010][44];

int main()
{
	scanf ("%d",&N);
	for (int i=0;i<N;i++){
		scanf ("%lld %lld",&X[i],&Y[i]);
		P[i] = (X[i] % 2 + Y[i] % 2 + 2) % 2;
	}

	for (int i=0;i<N;i++) if (P[i] != P[0]){
		puts("-1");
		return 0;
	}

	vector<long long> mv;
	for (int i=0;i<6+P[0];i++) mv.push_back(1);
	for (int i=1;i<32;i++) mv.push_back(1ll << i);

	long long sum = 0;
	for (int j=0;j<mv.size();j++) sum += mv[j];
	for (int j=mv.size()-1;j>=0;j--){
		auto l = mv[j];
		sum -= l;

		int dx[4] = {0,1,0,-1};
		int dy[4] = {1,0,-1,0};
		char ch[6] = "URDL";
		for (int i=0;i<N;i++) for (int k=0;k<4;k++){
			long long px = X[i] - dx[k] * l;
			long long py = Y[i] - dy[k] * l;
			if (abs(px) + abs(py) <= sum){
				X[i] = px;
				Y[i] = py;
				A[i][j] = ch[k];
				break;
			}
		}
	}

	printf ("%d\n",mv.size());
	for (int j=0;j<mv.size();j++) printf ("%lld%c",mv[j],j+1<mv.size()?' ':'\n');
	for (int i=0;i<N;i++) puts(A[i]);

	return 0;
}