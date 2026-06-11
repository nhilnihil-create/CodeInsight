#include <bits/stdc++.h>
#define s second
#define f first
#define pb push_back
#define endl '\n'
using namespace std;


typedef long long ll;
typedef pair<int,int> pii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string S,T;
	cin >> S >> T;

	vector<vector<int>> DP(S.size() + 1, vector<int>(T.size() + 1,0));

	for(int i = 1; i <= int(S.size()); i++){
		for(int j = 1; j <= int(T.size()); j++){
			if(S[i-1] == T[j-1]) DP[i][j] = DP[i-1][j-1] + 1;
			else DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
		}
	}

	string ans = "";

	int j = T.size() - 1;

	for(int i = (int)S.size() - 1; i >= 0; i--){
		if(j < 0) break;
		if(S[i] == T[j]) ans += S[i], j--;
		else{
			if(DP[i][j+1] == DP[i+1][j+1]) continue;
			else{
				j--;
				i++;
			}
		}
	}

	reverse(ans.begin(), ans.end());

	cout << ans << endl;

	return 0;
}
