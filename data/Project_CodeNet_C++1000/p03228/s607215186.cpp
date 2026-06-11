#include<bits/stdc++.h>
using namespace std;
using i64 = int_fast64_t;
#define rep(i, N) for(int (i) = 0; (i) < (N); (i)++)
#define all(v) (v).begin(), (v).end()
#define eb emplace_back
#define Cout(s) cout << s << endl
string Yes(bool b) {if(b){return "Yes";} else {return "No";}}
string YES(bool b) {if(b){return "YES";} else {return "NO";}}


int main(){
	i64 A, B, K;
	cin >> A >> B >> K;
	

	rep(i, K){
		if(A%2) A--;
		B += A/2;
		A /= 2;
		swap(A, B);
	}

	if(K%2) swap(A,B);
	cout << A << " "  << B << endl;
}
