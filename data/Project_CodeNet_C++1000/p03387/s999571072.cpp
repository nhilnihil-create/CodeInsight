#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int a[3];
	cin>>a[0]>>a[1]>>a[2];
	sort(a, a + 3);
	int ans = 1000000;
	for(int x = -100; x <= 100; x++){
		int tmp = 0;
		for(int i = 0; i < 3; i++){
			if(a[i] > x){
				tmp += a[i] - x;
			}else{
				tmp += (x - a[i] + 1)/2 + ((x^a[i])&1);
			}
		}
		ans = min(ans, tmp);
	}
	cout<<ans<<endl;

	return 0;
}