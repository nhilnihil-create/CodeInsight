#include<bits/stdc++.h>
#define ll long long
using namespace std;

 
int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

    string s;
    cin >> s;
    ll l = s.size(), ans = 0, b = 0;
    for(int i = 0; i < l; i++){
        if(s[i] == 'B') b++;
        else ans += b;
    }
    cout << ans;
 
 
    return 0;
}