#include <bits/stdc++.h>
#define all(x) ((x).begin(), (x).end())
#define sz(x) ((int) (x).size())
using namespace std;
typedef pair<int,int> ii;
typedef long long lint;

int arr[200005];

int main(){
	//freopen("i.txt","r",stdin);
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int n; cin >> n;
	
	for(int i = 1;i <= n;i++) cin >> arr[i];
	arr[0] = -1;
	
	lint ans = -1;
	for(int i = 1;i <= n;i++){
		if(arr[i] - arr[i-1] >= 2){
			cout << -1;
			return 0;
		}
		
		if(arr[i] == arr[i-1] + 1) ans++;
		else ans += arr[i];
		
		//cout << ans << "\n";
	}
	
	cout << ans;
}

