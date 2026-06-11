#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
	string s; cin >> s;
    ll ss = s.size();
 
    int a_count = 0;
    // int bc_count = 0;
    ll ans = 0;
    ll cnt = 0;
    
    int i = 0;
    while (i < ss-1) {
        if (s[i] == 'A') {
            a_count += 1;
            i += 1;
        } else if (s[i] == 'B' && s[i+1] == 'C') {
            ans += a_count;
            i += 2;
            // bc_count = 0;
        } else {
            a_count = 0;
            i += 1;
        }
    }
    cout << ans << endl;
	
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t =1; 
//	cin>>t; 
	while(t--)solve();
	return 0;
}
