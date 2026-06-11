#include <bits/stdc++.h>

#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;
using ll = long long;

const int INF = 1e8+10;

int n;
int a[3];
vector<int> v,ans(3,INF);

bool ok(int i,int j,int k){
	for(int u=0;u<n;++u){
		bool x = (((1<<u)&i) != 0);
		bool y = (((1<<u)&j) != 0);
		bool z = (((1<<u)&k) != 0);
		if((x&&y) || (x&&z) || (y&&z))
			return false;
	}
	return true;
}

int main(){
	fastIO;
	cin >> n;
	for(int i=0;i<3;++i) cin >> a[i];
	v = vector<int>(n);
	for(int &x:v) cin >> x;
	for(int i=1;i<(1<<n);++i){
		int mp_a=0,sz_a=0,qtd_a=-1;
		for(int u=0;u<n;++u){
			if(((1<<u)&i) != 0){
				qtd_a++;
				sz_a+=v[u];
			}
		}
		mp_a = 10*qtd_a;
		for(int j=1;j<(1<<n);++j){
			int mp_b=0,sz_b=0,qtd_b=-1;
			for(int u=0;u<n;++u){
				if(((1<<u)&j) != 0){
					qtd_b++;
					sz_b+=v[u];
				}
			}
			mp_b = 10*qtd_b;
			for(int k=1;k<(1<<n);++k){
				int sz_c=0,mp_c=0,qtd_c=-1;
				for(int u=0;u<n;++u){
					if(((1<<u)&k) != 0){ 
						qtd_c++;
						sz_c+=v[u];
					}
				}
				int nums = qtd_a+qtd_b+qtd_c;
				if(!ok(i,j,k) || nums > n){
					continue;
				}
				mp_c = 10*qtd_c;
				ll ans_a = abs(a[0]-sz_a)+mp_a;
				ll ans_b = abs(a[1]-sz_b)+mp_b;
				ll ans_c = abs(a[2]-sz_c)+mp_c;
				ll n_ans = ans_a + ans_b + ans_c;
				ll old_ans = ans[0]+ans[1]+ans[2];
				//cout << "n_ans = " << n_ans << " old_ans = " << old_ans << endl;
				if(n_ans < old_ans){
					ans[0] = ans_a;
					ans[1] = ans_b;
					ans[2] = ans_c;
				}
			}		
		}
	}
	int xd = ans[0]+ans[1]+ans[2];
	cout << xd << '\n';
	return 0;
}