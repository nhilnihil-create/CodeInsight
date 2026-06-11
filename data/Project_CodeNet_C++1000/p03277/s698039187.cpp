#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 998244353

int fen[100005];
int a[100005];
int b[100005];
int n;
void ref(){
	for(int i = 1 ; i <= n ; i ++)
		fen[i] = 0;
}
void upd(int p, int val){
    for(int i = p; i <= n; i += i & -i)
        fen[i] += val; 
}

int sum(int p) {
    int ans = 0;
    for(int i = p; i; i -= i & -i)
        ans += fen[i];
    return ans;
}
bool f(int u){
	ref();
	int ans = 0;
	vector<pair<int,int> > vp;
	for(int i = 1 ; i <= n ; i ++){
		b[i] = b[i - 1] + (a[i] >= u ? 1 : -1);
		if(b[i] >= 0) ans ++;
		vp.push_back({b[i], i});
	}
	sort(vp.begin(), vp.end());
	for(pair<int,int> p: vp){
		ans += sum(p.second);
		upd(p.second, 1);
	}
	return ans >= (n*(n + 1)/4);
}
signed main(){
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)
		cin >> a[i];
	int L = *min_element(a + 1, a + n + 1);
	int R = *max_element(a + 1, a + n + 1);
	while(L < R){
		//cout << L  << " " << R << endl;
		if(L == R - 1){
			if(f(R)) L = R;
			else R = L;
		}
		int M = (L + R) >> 1;
		if(f(M)) L = M;
		else R = M - 1;
	}
	cout << L;
}
