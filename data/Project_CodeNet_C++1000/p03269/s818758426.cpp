#include <stdio.h>
#include <vector>
using namespace std;

struct edge{int x,y,c;};
int N = 14; vector<edge> A;

int main()
{
	for (int i=0,p=1;i<12;i++,p*=3){
		A.push_back({N-i-1,N-i,0});
		if (p <= 1000000) A.push_back({N-i-1,N-i,p});
		if (p * 2 <= 1000000) A.push_back({N-i-1,N-i,p*2});
	}
	int L; scanf ("%d",&L); L--;
	A.push_back({1,N,L});
	for (int i=0,p=1;L;i++,p*=3,L/=3){
		int u = L % 3;
		for (int k=0;k<u;k++){
			A.push_back({1,N-i,(L-u+k)*p});
		}
	}

	printf ("%d %d\n",N,A.size());
	for (auto &e : A) printf ("%d %d %d\n",e.x,e.y,e.c);
	return 0;
}