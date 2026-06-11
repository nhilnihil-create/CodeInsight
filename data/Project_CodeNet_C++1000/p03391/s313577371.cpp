#include <iostream>
#define ll long long
using namespace std;

ll A[200010], B[200010];

int main() {
	int N;
	cin >> N;
	ll sum=0;
	for(int i=0; i<N; ++i){
		cin >> A[i] >> B[i];
		sum += A[i];
	}
	ll mn=sum;
	for(int i=0; i<N; ++i){
		if(A[i]>B[i]){
			mn=min(mn, B[i]);
		}
	}
	cout << sum-mn << endl;
	return 0;
}