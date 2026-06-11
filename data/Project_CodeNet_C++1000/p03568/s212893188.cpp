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

int solve(int arr[], int odds, int pos, int max){
	if(pos == max){
		//cout << odds << endl;
		return (odds!=max?1:0);
	}
	int a = solve(arr, ((arr[pos]-1)%2==0?odds:odds+1), pos+1, max);
	int b = solve(arr, ((arr[pos]%2)==0?odds:odds+1), pos+1, max);
	int c = solve(arr, ((arr[pos]+1)%2==0?odds:odds+1), pos+1, max);
	return a+b+c;
}

int main() {
	int N;
	cin >> N;
	int arr[N];
	REP(i, 0, N) cin >> arr[i];
	
	cout << solve(arr, 0, 0, N);


}
