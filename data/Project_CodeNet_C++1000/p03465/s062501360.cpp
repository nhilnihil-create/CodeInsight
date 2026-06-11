#include <iostream>
#include <bitset>
using namespace std;

int A[2010];
bitset<2000010> bs;

int main() {
	int N;
	cin >> N;
	int sum=0;
	for(int i=0; i<N; ++i){
		cin >> A[i];
		sum += A[i];
	}
	bs[0]=1;
	for(int i=0; i<N; ++i){
		bs |= (bs<<(A[i]));
	}
	int ans=sum/2;
	while(!bs[ans]) --ans;
	cout << sum-ans << endl;
	return 0;
}