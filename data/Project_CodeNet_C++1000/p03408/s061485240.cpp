#include <bits/stdc++.h>


using namespace std;

#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
#define mk make_pair
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define sz(x) (int) (x).size()


void go(){
	int n;
	cin >> n;
	unordered_map<string,int> b;
	for(int i=0;i<n;i++) {
		string s;
		cin >> s;
		b[s]++;
	}
	int t;
	cin >> t;
	for(int i=0;i<t;i++) {
		string s;
		cin >> s;
		b[s]--;
	}
	int ans=0;
	for(auto p : b) {
		if(p.se>ans) ans=p.se;
	}
	cout << ans;
	
}
int main(){
   fastio();
   go();

   return 0;
}


