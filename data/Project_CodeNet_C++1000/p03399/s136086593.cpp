#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	int A, B, C, D;
	cin >> A >> B >> C >> D;
	
	int Q = min({ A,B });
	int W = min({ C,D });

	cout << Q + W << endl;
}