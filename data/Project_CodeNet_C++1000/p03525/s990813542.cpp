#include <bits/stdc++.h>
#define ALL(A) (A).begin(),(A).end()
#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(void){
	int N;
	cin >> N;
	vector<int> c(25);
	c[0] ++;
	rep(i,N){
		int a;
		cin >> a;
		c[a]++;
	}
	rep(i,13){
		if(c[i] >=3){
			cout << 0 << endl;
			return 0;
		}
	}
	if(c[0] >= 2 || c[12] >=2){
		cout << 0 << endl;
		return 0;
	}
	int ans = 0;
	for(int bit=0;bit< (1<<13);bit++){
		vector<int> t(25);
		for(int i=0;i<13;i++){
			if(c[i]>=2){
				t[i]++;
				t[(24-i)%24]++;
				continue;
			}
			if(bit&(1<<i)){
				if(c[i]){
					t[(24-i)%24]++;
				}
			}else{
				if(c[i])t[i]++;
			}
		}
		int temp = 24;
		rep(i,24)rep(j,24){
			if(i==j)continue;
			if(t[i]==0 || t[j]==0)continue;
			temp = min({temp,abs(i-j),24-i+j,24-j+i});
		}
		ans = max(ans,temp);
	}
	cout << ans << endl;
}