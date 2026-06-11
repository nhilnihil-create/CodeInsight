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
	int a,b,c;cin>>a>>b>>c;
	int k;cin>>k;
	int s=a+b+c;
	int s1=s,s2=s,s3=s;
	int ans=0;
	while(k) {
		s1-=a, s1+=a*2;
		s2-=b, s2+=b*2;
		s3-=c, s3+=c*2;
		ans=max({s1,s2,s3});
		a*=2;
		b*=2;
		c*=2;
		k--;
	}
	cout << ans;
}
int main(){
   
   fastio();
   cin.tie(0);
   cout.tie(0);

   go();

   return 0;
}


