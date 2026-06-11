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
	int n,k;cin>>n>>k;
	int x=1;
	while(n--) {
		if(x*2<x+k) {
			x*=2;
		}else {
			x+=k;
		}
	}
	cout<< x;
}
int main(){
   
   fastio();
   cin.tie(0);
   cout.tie(0);

   go();

   return 0;
}


