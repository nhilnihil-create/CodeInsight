#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
int a[N], b[N], aa[N], bb[N], n;

int low_binary(int pos, int value){
	int lo = 0, hi = n - 1, mid, res = -1;
	while(lo <= hi){
		mid = (lo + hi) >> 1;
		if(aa[pos] + bb[mid] >= value){
			res = mid;
			hi = mid - 1;
		}
		else{
			lo = mid + 1;
		}
	}
	return res;
}

int high_binary(int pos, int value){
	int lo = 0, hi = n - 1, mid, res = -1;
	while(lo <= hi){
		mid = (lo + hi) >> 1;
		if(aa[pos] + bb[mid] >= value){
			hi = mid - 1;
		}
		else{
			res = mid;
			lo = mid + 1;
		}
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  	int i, bit;
	int ans = 0;
	cin >> n;
	for(i = 0; i < n; ++i)cin >> a[i];
	for(i = 0; i < n; ++i)cin >> b[i];
	for(bit = 0; bit < 31; ++bit){
		int T = (1 << bit);
		for(i = 0; i < n; ++i){
			aa[i] = a[i] % (2*T);
			bb[i] = b[i] % (2*T);
		}

		sort(bb, bb + n);

		int ct = 0, lower_bound, upper_bound;

		for(i = 0; i < n; ++i){
			lower_bound = low_binary(i, T);
			upper_bound = high_binary(i, 2*T);
			if(lower_bound != -1)
				ct = ct + (upper_bound - lower_bound + 1);
			lower_bound = low_binary(i, 3*T);
			upper_bound = high_binary(i, 4*T);
			if(lower_bound != -1)
				ct = ct + (upper_bound - lower_bound + 1);	
		}


		if(ct & 1)
			ans = ans + T;
	}
	cout << ans << endl;
	return 0;
}