#include <bits/stdc++.h>
using namespace std;


int main(){
	
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

	int n;
	string s;
	cin >> n >> s;
	int cnt=0;
	for(auto i:s) if(i=='R') cnt++; else cnt--;
	if(cnt>0) cout << "Yes";
	else cout << "No";


	


 
 
	
 
}