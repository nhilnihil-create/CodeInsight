   //=========================================\\   
  //          @Author : SajidZakaria           \\
 //     @File Created : 2020-05-02 19:30:24     \\
//===============================================\\

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define endl '\n'

int ans[200005];

int main(){
	ios_base::sync_with_stdio(false);
	int n, x;
	cin >> n;

	for(int i=1; i<=n; i++) {
		cin >> x;
		ans[x] = ans[x-1] + 1;
	}

	int mx = 0;
	for(int i=1; i<=n; i++) mx = max(mx, ans[i]);

	cout << n - mx << endl;

	return 0;
}