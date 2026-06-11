#include <bits/stdc++.h>
#define cout16 cout << setprecision(16) 
#define rep(i,n) for(int i=0;i<n;i++ )
#define rep2(i,f,n) for(int i=f;i<n;i++ )
#define SORT(A) sort(A.begin(),A.end())
#define REV(A) reverse(A.begin(),A.end())
typedef long long int ll;
using vi = std::vector<int>;
using vvi = std::vector<std::vector<int>>;
using vll = std::vector<ll>;
using vvll = std::vector<std::vector<ll>>;
using P = std::pair<int,int>;
using vp = std::vector<P>;
using namespace std;
#define INF 1001001001
#define LL_INF 1001001001001001001
#define fi first
#define se second

int main(void) {
	int n; cin >> n;
	int ans = 0;
	int lr=0,l=0,r=0;
	rep(i,n){
		string s; cin >> s;
		rep(j,s.size()-1){
			string x;
			x += s[j];
			x += s[j+1];
			if(x=="AB") ans++;
		}
		if(s[0]=='B'&&s[s.size()-1]=='A') lr++;
		else if(s[0]=='B') l++;
		else if(s[s.size()-1]=='A') r++;
	}
//	cout << ans << endl;
//	cout << lr << " " << l << " " << r << endl;
	ans += max(0,lr-1);
	lr = min(lr,1);
	if(l!=0&&lr!=0){
		ans++;
		lr--;
	}else if(r!=0&&lr!=0){
		ans++;
		lr--;		
	}
	ans += min(l,r);
	cout << ans << endl;
}
