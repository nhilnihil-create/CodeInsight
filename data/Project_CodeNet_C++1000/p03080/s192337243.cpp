// Abhishek Katara
// Indian Institute of Information Technology, Vadodara

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
 
int main(){
	ll n, cr = 0, cb = 0;
    cin >> n;
	string str;
	cin >> str;
	for(ll i=0;i<n;i++){
		if(str[i] == 'R'){
			cr++;
		}
		else{
			cb++;
		}
	}
	if(cr > cb){
		cout << "Yes" << endl;
	}
	else{
		cout << "No" << endl;
	}
}
