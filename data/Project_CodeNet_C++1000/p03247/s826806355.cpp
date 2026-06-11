#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

#define fr first
#define sc second

const ll dx[4] = { -1,1,0,0 };
const ll dy[4] = { 0,0,-1,1 };
const char c[4] = { 'R','L','U','D' };

int main(){
	ll n;
	ll x[1002],y[1002];
	scanf("%lld",&n);
	for(int i = 1 ; i <= n ; i ++){
		scanf("%lld%lld",&x[i],&y[i]);
	}
	
	ll cnt[2] = {};
	for(int i = 1 ; i <= n ; i ++){
		cnt[abs(x[i]+y[i])%2] ++;
	}
	if(cnt[0] != 0 && cnt[1] != 0){
		puts("-1");
		return 0;
	}
	
	if(cnt[0] != 0){
		vector<ll> vec;
		ll sum = 0;
		for(int i = 0 ; i < 20 ; i ++){
			vec.push_back(sum+1);
			sum += 2*(sum+1);
		}
		cout << 40 << endl;
		for(int i = vec.size()-1 ; i >= 0 ; i --){
			cout << vec[i] << " " << vec[i];
			if(i==0)cout << endl;
			else cout << " ";
		}
		for(int q = 1 ; q <= n ; q ++){
			string ret = "";
			for(int i = vec.size()-1 ; i >= 0 ; i --){
				for(int s = 0 ; s < 4 ; s ++){
					for(int t = s ; t < 4 ; t ++){
						ll nx = x[q]+(dx[s]+dx[t])*vec[i];
						ll ny = y[q]+(dy[s]+dy[t])*vec[i];
						if(abs(nx)+abs(ny) <= vec[i]-1){
							x[q] = nx;
							y[q] = ny;
							ret += c[s];
							ret += c[t];
							goto nex2;
						}
					}
				}
				nex2:;
			}
			cout << ret << endl;
		}
	}
	else {
		vector<ll> vec;
		ll sum = 1;
		for(int i = 0 ; i < 19 ; i ++){
			vec.push_back(sum+1);
			sum += 2*(sum+1);
		}
		cout << 39 << endl;
		for(int i = vec.size()-1 ; i >= 0 ; i --){
			cout << vec[i] << " " << vec[i] << " ";
		}
		cout << 1 << endl;
		for(int q = 1 ; q <= n ; q ++){
			string ret = "";
			for(int i = vec.size()-1 ; i >= 0 ; i --){
				for(int s = 0 ; s < 4 ; s ++){
					for(int t = s ; t < 4 ; t ++){
						ll nx = x[q]+(dx[s]+dx[t])*vec[i];
						ll ny = y[q]+(dy[s]+dy[t])*vec[i];
						if(abs(nx)+abs(ny) <= vec[i]-1){
							x[q] = nx;
							y[q] = ny;
							ret += c[s];
							ret += c[t];
							goto nex;
						}
					}
				}
				nex:;
				//cout << x[q] << " " << y[q] << endl;
			}
			if(x[q] == 1)ret += "R";
			else if(x[q] == -1)ret += "L";
			else if(y[q] == 1)ret += "U";
			else ret += "D";
			cout << ret << endl;
		}
	}
}
