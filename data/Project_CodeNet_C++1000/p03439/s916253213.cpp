#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) FOR(i,0,n)
#define RFOR(i,a,b) for(int i=(a)-1;i>=(b);i--)
#define rrep(i,n) RFOR(i,n,0)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;



int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	cout << 0 << endl;
	cout.flush();

	string sts0;
	cin >> sts0;
	if(sts0 == "Vacant") return 0;

	int lb = 0, ub = n;

	while(true){
		int mid = (lb + ub) >> 1;

		cout << mid << endl;
		cout.flush();

		string tmp;
		cin >> tmp;
		if(tmp == "Vacant") return 0;

		if((mid % 2 == 0 && tmp == sts0)
			|| (mid % 2 == 1 && tmp != sts0)){
			lb = mid;
			// cout << "lb" << endl;

		}else{
			ub = mid;
			// cout << "ub" << endl;
		}

		// if(cond(mid)) ub = mid;   // Answer is in (lb, mid]
		// else lb = mid;            // Answer is in (mid, ub]
	}
}
