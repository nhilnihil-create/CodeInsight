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
	int N, A, B;
	cin >> N >> A >> B;
	vector<int> P(N);
	rep(i, N) cin >> P[i];
	int a = 0, b = 0, c = 0;
	for(auto& p : P){
		if(p <= A) a++;
		else if(p <= B) b++;
		else c++;
	}

	Cout(min({a, b, c}));
}
