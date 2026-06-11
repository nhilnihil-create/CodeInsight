#include<iostream>
using namespace std;

int main() {
	int N, A, B;
	cin >> N >> A >> B;
	int total,x,res;
	res=0;
	for(int i=1;i<=N;i++){
		total = 0;
		x = i;
		while(true) {
			total += x%10;
			if(x/10 < 1) break;
			else x/= 10;
		}
		if(total >= A && total <= B) res+=i;
	}
	cout << res << endl;
}