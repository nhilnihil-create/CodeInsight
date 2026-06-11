//#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#include <math.h>
 
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
// using namespace __gnu_pbds;
// template<class T> using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
 
#define ll long long int
#define ull unsigned long long int
 
#define lp(i,n) 	    for(int i=0;i<(int)(n);i++)
#define lpi(i, j, n)    for(int i=(j);i<(int)(n);i++)
#define lpd(i, j, n)    for(int i=(j);i>=(int)(n);i--)
 
#define all(v)  	 ((v).begin()), ((v).end())
#define sz(v)    	 ((int)((v).size()))
#define clr(v, d)    (memset(v, d, sizeof(v)))
#define PB           push_back
#define MP           make_pair
#define N 100002

#define PI 3.14159265359
 
ll gcd(ll a, ll b);
vector<string> split(string target,unsigned char c );
 
 
ll n,k,t,m,x,y;
ll ans;
ll mod=1e9 +7;
pair<double,double>v[102];
bool isPrime(ll h); 

string s;
map<pair<string,string>,ll>mp;
void calc(int num){
	string red="",blue="";
	lp(i,n){
		if(num & (1<<i))red+=s[i];
		else blue+=s[i];
	}
	mp[MP(red,blue)]++;
}

ll solve(int num){
	string blue="",red="";
	lp(i,n){
		if(num & (1<<i)){
			blue+=s[i+n];
		}
		else red+=s[i+n];
	}
	reverse(all(blue));
	reverse(all(red));
	return mp[MP(blue,red)];
}
int main() {
// freopen("d.in","r",stdin); 
// 	freopen("d_out.txt","w",stdout); 
cout.precision(2);
ios_base::sync_with_stdio(false);
cin.tie(NULL);  cout.tie(NULL);

cin>>n>>s;
x=1<<n;
lpi(i,1,x-1)calc(i);

lpi(i,1,x-1)ans+=solve(i);
ans+=2;
lp(i,n){
	if(s[i]!=s[2*n -1 -i]){
		ans-=2; break;
	}
}
cout<<ans;




	

}



 

	

ll gcd(ll a, ll b){
	return b==0?a:gcd(b,a%b);
}
 
 
vector<string> split(string target,unsigned char c ){
	string d="";
	vector<string>arr;
	for(auto n:target)
	{
		if(n!=c)
		d+=n;
		else if(d!="")
		arr.push_back(d),d="";
	}
	if (d!="")
	arr.push_back(d),d="";
	return arr;
}
// bool isPrime(ll h){
//      for(ll i=0;primes[i]*primes[i]<= h;i++)
//      if (h%primes[i]==0)
//      	return 0;
//      return h!=1;
//  }
 bool isPrime(ll g){
   if((g%2==0 && g>2) || g==1)return 0;
   for(ll i=3;i*i<=g;i+=2)if(g%i==0)return 0;
   return 1;   
 
 }