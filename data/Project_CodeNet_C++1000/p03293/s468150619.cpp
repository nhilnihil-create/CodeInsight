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
#define print_vec(vec) for(int i=0;i<sz(vec);i++) cout << vec[i] << " ";
#define FORin(vec) for(int& x : vec) cin>>x;

void go(){
	string s,t;cin>>s>>t;
	bool ans=false;
	for(int i=0;i<sz(s);i++) {
		string tmp=s.back() + s.substr(0,sz(s)-1);
		if(tmp==t) {
			ans=true;
			break;
		}
		s=tmp;
	}
	if(ans) cout << "Yes";
	else cout << "No";
}
int main(){
   
   fastio();
   cin.tie(0);
   cout.tie(0);

   go();

   return 0;
}


