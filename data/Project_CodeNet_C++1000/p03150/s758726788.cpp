#include<bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define repk(i,k,n) for (ll i = k; i < (ll)(n); ++i)
#define MOD 1000000007
typedef long long  ll;

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	string s;
    cin >> s;
    int len = s.size();
    string ke = "keyence";
    for(int i = 0; i <= 7; i++){
        // cout << s.substr(0, i) << " = " <<  s.substr(len-7+i) << endl;
        if(s.substr(0, i) + s.substr(len-7+i) == ke){
           cout << "YES" << endl;
           return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}