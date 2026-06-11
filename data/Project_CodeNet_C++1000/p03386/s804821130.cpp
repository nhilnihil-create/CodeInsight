#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> pi;
typedef pair<int,int> vi;

#define F first
#define S second
#define PB push_back
#define MK make_pair
#define REP(i, a, b) for (int i=a; i < b; i++)


bool sort_by(vi c, vi d){
	return c.S < d.S;
}

int main() {
	int A, B, K;
	cin >> A >> B >> K;
	
	if(B-A < 2*K) REP(i, A, B+1) cout << i << endl;
	else{
		REP(i, A, A+K) cout << i << endl;
		for(int i=B-K+1; i < B+1; i++)cout << i << endl;
	}

}
