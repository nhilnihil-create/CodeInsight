#include<bits/stdc++.h>
#define ll long long
#define fastio  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const int MOD=1000000007;
#define PI acos(-1)
using namespace std;
ll gcd(ll x, ll y)
{                     
        return (x==0)? y : gcd(y % x, x);
}

int main(){
     string s ; cin >> s ;
     int x  = s.size();
     int res = 1e7;
     for(int i =0 ; i < x-2 ; i++){
     	   int x = s[i] - '0';
     	   int y = s[i+1] - '0';
     	   int z = s[i+2] -'0';
     	   int ans = x*100 + y*10+ z;
     	   res = min(res , abs(ans-753));
	 }
	 cout << res << endl;
}