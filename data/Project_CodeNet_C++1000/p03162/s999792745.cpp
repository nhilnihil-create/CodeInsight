#include<iostream>

using namespace std;
int main(){
	int N;
	int a[100005], b[100005], c[100005];
	scanf("%d", &N);
	for(int i = 1; i<=N ; i++){
		cin >> a[i] >> b[i] >> c[i];
	}
	for(int i = 2 ; i<=N ; i++){
		int aa = a[i-1];
		int bb = b[i-1];
		int cc = c[i-1];
		a[i] = a[i] + max(bb, cc);
		b[i] = b[i] + max(aa, cc);
		c[i] = c[i] + max(bb, aa);
	}
	cout << max(a[N], max(b[N], c[N])) << endl;

}