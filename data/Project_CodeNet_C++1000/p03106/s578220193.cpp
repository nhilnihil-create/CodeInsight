#include <bits/stdc++.h>


using namespace std;


#define ll long long
#define mk make_pair
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define sz(x) (int) (x).size()


ll sum(int n);


void go(){
	int a,b,k;cin>>a>>b>>k;
	int ans=0;
	for(int i=max(a,b);i>=0;i--) {
		if(b%i==0&&a%i==0) {
			k--;
		}
		if(k==0) {
			ans=i;
			break;
		}
	}
	cout << ans;
}
int main(){
   
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   go();

   return 0;
}

ll sum(int n){                
   if(n == 0){
      return n;
   }else{
      return sum(n/10) + n%10;
   }
}
