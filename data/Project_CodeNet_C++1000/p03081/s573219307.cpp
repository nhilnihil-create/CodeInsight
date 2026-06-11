// Abhishek Katara
// Indian Institute of Information Technology, Vadodara

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
 
int main(){
	ll n, q;
	cin >> n >> q;
	string str;
	cin >> str;
	vector<string> t, d;

	for(ll i=0;i<q;i++){
		string t1, d1;
		cin >> t1 >> d1;
		t.push_back(t1);
		d.push_back(d1);
	}
	ll l = 0, r = n-1;
    for(ll i=q-1;i>=0;i--){
    	if(d[i][0] == 'L'){
      		if(l < n && str[l] == t[i][0]){
    			l++;
      		}
      		if(r < n-1 && str[r+1] == t[i][0]){
      			r++;
      		}
    	}
    	else{
    			if(r >= 0 && str[r] == t[i][0]){
      				r--;
    			}
      			if(l >= 1 && str[l-1] == t[i][0]){
      				l--;
      			}
    		}
 		}
 	cout << max(0ll, r-l+1) << endl;
}