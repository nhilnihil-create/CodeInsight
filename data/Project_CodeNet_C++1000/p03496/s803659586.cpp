#include <iostream>
using namespace std;

int a[55];

int main() {
	int N;
	cin >> N;
	int mx=1;
	for(int i=1; i<=N; ++i){
		cin >> a[i];
		if(abs(a[mx])<abs(a[i])) mx=i;
	}
	cout << 2*(N-1) << endl;
	for(int i=1; i<=N; ++i){
		if(i!=mx) cout << mx << ' ' << i << endl;
	}
	if(a[mx]>0){
		for(int i=1; i+1<=N; ++i){
			cout << i << ' ' << i+1 << endl;
		}
	}else{
		for(int i=N; i>=2; --i){
			cout << i << ' ' << i-1 << endl;
		}
	}
	return 0;
}