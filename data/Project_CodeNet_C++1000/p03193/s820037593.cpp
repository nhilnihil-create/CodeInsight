#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<climits>
#include<set>
#include<utility>
#include<typeinfo>
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
typedef set<int> S;
#define rep(i, n) for(int i=0; i<n; i++)
const ll MOD=1e9+7;

int main(){

	int N, H, W, A, B, ans = 0;
	cin >> N >> H >> W;
	for(int i = 0; i < N; i++){
		cin >> A >> B;
		if(H <= A && W <= B){
			ans++;
		}
	}
	cout << ans << endl;

	return 0;
}