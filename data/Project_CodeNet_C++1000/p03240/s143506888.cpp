#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define what_is(x) cerr << #x << " is " << x << endl;
#define MT make_tuple
#define eb emplace_back
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

#define REP(i,a,b) for (int i = a; i <= b; i++)
#define FOR(i,n) for (int i=0;i < n ; i++)
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}
clock_t startTime;
long double getTime(){
	return (long double)(clock()-startTime)/CLOCKS_PER_SEC;
}

int main(){
	startTime=clock();
	ll a,b,n;
	cin >> n;
	ll x[n],y[n],h[n];
	for(int i=0;i < n;i++){
		cin >> x[i] >> y[i] >> h[i];
	}
	for(int i=0;i <=100;i++){
		for(int j=0;j <=100;j++){
			int t=0;
			while(h[t]==0)t++;
			if(h[t] > 0){
				ll ans=h[t]+abs(x[t]-i)+abs(y[t]-j);
				if(ans >0){
					int k=0;
					while(k < n && h[k]==max(ans-abs(x[k]-i)-abs(y[k]-j),0LL))
						k++;
					if(k==n){
						cout << i <<" " << j <<" "<< ans;
						return 0;
					}
				}
			}
		}
	} 	

	return 0;
}