#include <bits/stdc++.h>

using namespace std;

template <class T>inline T updmax(T &a, T b) { return a = max(a, b); }
template <class T>inline T updmin(T &a, T b) { return a = min(a, b); }

int main()
{
	int Q;
	cin >> Q;
	for(int q=0; q < Q; q++){
		long long a, b;
		cin >> a >> b;
		if(a > b)swap(a, b);
		if(a + 1 >= b){
			cout << 2*a -2 << "\n";
		}else{
			long long ok = 1, ng = 1e9+5;
			while(abs(ok-ng)>1){
				long long mid = (ok+ng)/2;
				bool flag = false;
				if(mid * mid < a*b)flag=true;
				if(flag)ok=mid;
				else ng=mid;
			}
			long long c = ok;
			if(c*(c+1) >= a*b)cout << 2*c -2 << "\n";
			else cout << 2 * c - 1 << "\n";
		}
	}
	return 0;
}