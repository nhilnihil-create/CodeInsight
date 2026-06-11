#include<iostream>
#include<cmath>
using namespace std;

int n, a, b, m, q, r, sum, total=0;
int main(){
	cin >> n >> a >> b;
	for(int i = 1; i <= n; i++){
		m = i;
		sum = 0;
		while(m > 0){
			q = m / 10; r = m % 10;
			sum += r;
			m = q;
		}
		if(a<=sum && sum <= b){
//			cout << i << endl;
			total += i;
		}
	}
//	cout << "total" << endl;
	cout << total << endl;
}
