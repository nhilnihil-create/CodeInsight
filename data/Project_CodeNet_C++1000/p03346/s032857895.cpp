#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
	int n;
	cin >> n;
	
	vector<int> p(n), idx(n);
	rep(i,n){
		int tmp;
		cin >> tmp;
		p[i] = --tmp;
		idx[tmp] = i;
	}
	
	int now = 1;
	int cnt = 0;
	rep(i,n-1){
		if(idx[i+1] > idx[i]){
			now++;
		}
		else{
			cnt = max(cnt,now);
			now = 1;
		}
	}
  cnt = max(cnt,now);
	int res = n-cnt;
	
	cout << res << endl;
	return 0;
}