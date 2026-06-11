#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;
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
	ll T, N, H, K;
	long long T1, N1;
	cin >> T >> N >> H >> K;
	if((T > N? (long long)T-N:(long long)N-T) > 10e18) cout << "Unfair";
	else{
		T1 = (long long) T;
		N1 = (long long) N;
		cout << (K%2==0? T1-N1: N1-T1);
	}



	

}
