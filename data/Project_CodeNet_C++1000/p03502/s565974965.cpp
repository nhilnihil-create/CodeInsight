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

int sum(int n) {
	if(n==0) return n;
	else return n%10 + sum(n/10);
}
void go(){
	int n;cin>>n;
	if(n%sum(n)==0) cout << "Yes";
	else cout << "No";
}
int main(){
   
   fastio();
   cin.tie(0);
   cout.tie(0);

   go();

   return 0;
}


