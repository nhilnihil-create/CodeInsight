#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<set>
#include<cmath>
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define sz(a) (int)a.size()
using namespace std;

ll INF = 1000000007;

// a^n mod を計算する
long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}


int main() {
	string s;
	cin >> s;
	vector<int> a, b, c, d;
	rep(i, sz(s)) {
		if (s[i] == 'A') a.push_back(i);
		else if (s[i] == 'B') b.push_back(i);
		else if (s[i] == 'C') c.push_back(i);
		else {
			b.push_back(i);
			d.push_back(i);
		}
	}
	ll ans = 0;
	rep(i, sz(b)) {
        bool flag;
        if(lower_bound(d.begin(),d.end(),b[i])!=d.end()&&*lower_bound(d.begin(),d.end(),b[i])==b[i]) flag=true;
        else flag=false;
		auto itea = lower_bound(a.begin(), a.end(), b[i]);
		auto itead = lower_bound(d.begin(), d.end(), b[i]);
        
		auto itec = upper_bound(c.begin(), c.end(), b[i]);
		auto itecd = upper_bound(d.begin(), d.end(), b[i]);
      
      if(flag){
        ans+=(ll)(itea-a.begin())*(ll)(c.end()-itec)*modpow((ll)3,(ll)(sz(d)-1),INF);
      ans%=INF;
        ans+=(ll)(itea-a.begin())*(ll)(d.end()-itecd)*modpow((ll)3,(ll)(sz(d)-2),INF);
      ans%=INF;
        ans+=(ll)(itead-d.begin())*(ll)(c.end()-itec)*modpow((ll)3,(ll)(sz(d)-2),INF);
      ans%=INF;
        ans+=(ll)(itead-d.begin())*(ll)(d.end()-itecd)*modpow((ll)3,(ll)(sz(d)-3),INF);
        ans%=INF;
      }else{
       ans+=(ll)(itea-a.begin())*(ll)(c.end()-itec)*modpow((ll)3,(ll)(sz(d)),INF);
      ans%=INF;
        ans+=(ll)(itea-a.begin())*(ll)(d.end()-itecd)*modpow((ll)3,(ll)(sz(d)-1),INF);
      ans%=INF;
        ans+=(ll)(itead-d.begin())*(ll)(c.end()-itec)*modpow((ll)3,(ll)(sz(d)-1),INF);
      ans%=INF;
        ans+=(ll)(itead-d.begin())*(ll)(d.end()-itecd)*modpow((ll)3,(ll)(sz(d)-2),INF);
        ans%=INF;
      }
    }
	cout << ans << endl;
}
