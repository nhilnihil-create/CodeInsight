#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 5;
#define ex(x) return cout << x << endl, 0
int n, a[MAXN], b[MAXN];
int ans = 0;
ll sum;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n;
	for(int i = 0; i < n;i ++) cin >> a[i], sum += a[i];
	for(int i = 0; i < n;i ++) cin >> b[i], sum -= b[i];
	if( sum < 0) ex(-1);
	sum = 0;
	vector< int > vec;
	vec.clear();
	for(int i = 0; i < n; i++){
		if( b[i] > a[i]) sum += b[i] - a[i], ans ++;
		else if(a[i] > b[i]) vec.push_back(a[i] - b[i]);
	}
	sort(vec.begin(), vec.end());
	while( sum > 0 ){
		sum -= vec.back();
		vec.pop_back();
		ans ++;
	}
	ex(ans);
    return 0;
}

