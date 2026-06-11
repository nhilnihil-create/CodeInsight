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

int calculate(int n){
	int digit_sum = 0;
	while(n > 0){
		digit_sum += n % 10;
		n/=10;
	}
	return digit_sum;
}

int solve(string N){
	int ans = 0;
	REP(i, 0, (int)N.size()) if(N[i] != '9') ++ans;
	
	//if (N.size() == 1) ans = N[0] - '0';
	if (ans == 1 && N[0] != '9') ans = (N[0]-'0')+9*((int)N.size()-1);
	else if( ans == 0) ans = 9*((int)N.size());
	else ans = (N[0]-'0')+9*((int)N.size()-1)-1;
	return ans;
}

int test(int n){
	int m = 0;
	REP(i, 1, n+1){
		int d = calculate(i);
		m = max(d, m);
		//string s(1, i);
		int solution = solve(to_string(i));
		if(m != solution)
			cout<< i << " "  << m << " " << solution << endl;
	}
	
	return m;
}

int main() {
	string N;
	cin >> N;
	
	//test(1000000);
	cout << solve(N);
	
	
	//if(ans == 0) ans=((int)N.size() - 1)*9;
	//cout << ans;
 

}
