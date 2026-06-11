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
	int n;cin>>n;
	if(n<1200) cout << "ABC";
	else if(n<2800) cout << "ARC";
	else cout << "AGC";
}
int main(){
   
   fastio();
   cin.tie(0);
   cout.tie(0);

   go();

   return 0;
}


