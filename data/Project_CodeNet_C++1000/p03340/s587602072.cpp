#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;
	uint32_t *A = new uint32_t[200000];
	for(int n=0; n<N; n++){
		cin >> A[n];
	}

	uint64_t res = 0;
	uint32_t bits = 0x00;
	int nm = 0;
	for(int n=0; n<N; n++){
		while(nm < N && (A[nm] & bits) == 0x00){
			bits |= A[nm];
			nm ++;
		}
		res += nm - n;
		bits &= ~(A[n]);
	}

	cout << res;
	return 0;
}
