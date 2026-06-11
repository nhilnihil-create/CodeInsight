#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)

typedef long long ll;
typedef pair<ll,int> P;

int main(){
	int N, K;
	cin >> N >> K;
	string S;
	cin >> S;

	vector<int>  Z;
	int now = 1;
	int cnt = 0;
	rep(i,N){
		if(S[i]=='0'+now)cnt++;
		else { Z.push_back(cnt); now ^= 1; cnt=1; }
	}
	if(cnt!=0)Z.push_back(cnt);
	if(Z.size()%2 == 0)Z.push_back(0);

	int Add = 2 * K + 1;

	vector<int> sum(Z.size() + 1);
	rep(i,(int)Z.size()){ sum[i+1] = sum[i] + Z[i]; }

	int ans = 0;
	for(int i=0; i<(int)Z.size(); i+=2){
		int left = i;
		int right = min(i+Add, (int)Z.size());
		int tmp = sum[right] - sum[left];

		ans = max(ans, tmp);
	}

	cout << ans << endl;
}

