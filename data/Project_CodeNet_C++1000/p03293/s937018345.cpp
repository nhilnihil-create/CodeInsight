#include <bits/stdc++.h>

using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
#define  endl 			"\n"
#define  FOR(i, a, n)   for (ll i = a; i < n; i++)
#define  ROF(i, a, n)   for (ll i = a; i >= n; i--)
#define  all(x)         (x).begin(), (x).end()
#define  mset(x, val)   memset(x,val,sizeof(x))
#define  dline          cout<<"///REACHED///\n";

typedef long long ll;

const ll   MOD   =  1e+9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   MAXN  =  4e+5+7;



// void solve(){
// 	ll n,m,k,ans=0;
// 	cin>>n>>m>>k;
// 	if(m>n/k){
// 		ll p1 =n/k;
// 		ll remjokers=m-n/k;
// 		if(remjokers > k-1){
// 			ans=remjokers/(k-1);
// 		}
// 		else{
// 			cout<<abs(p1-1)<<endl;
// 			return;
// 		}
// 		cout<<abs(p1-(ans+ans*(k-1)))<<endl;
// 		return;
// 	}
// 	if(m<n/k){
// 		cout<<m<<endl;
// 		return;
// 	}


// }

vector<ll> arr;
ll n;
ll findlcm() 
{ 
	// Initialize result 
	ll ans = arr[0]; 

	// ans contains LCM of arr[0], ..arr[i] 
	// after i'th iteration, 
	for (int i = 1; i < n; i++) 
		ans = (((arr[i] * ans)) / 
				(__gcd(arr[i], ans))); 

	return ans; 
} 
ll f(ll num){
	ll temp=0;
	FOR(i,0,n){
		temp+=num%arr[i];
	}
	return temp;
}
void solve(){
	cin>>n;
	arr.resize(n);
	for(ll&x:arr) {cin>>x;}
	
	ll lcm = findlcm();
	lcm--;
	ll ans = f(lcm);
	cout<<ans;

}



int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	string s1,s2;
	cin>>s1>>s2;
	int pos;
	for(int i=0;i<s2.length();i++){
		if(s1[0]==s2[i]){
			pos=i;
			for(int i=0;i<s2.length();i++){
				if(s1[i]!=s2[(i+pos)%s2.length()]){
					// debug(s1[i],s2[(i+pos)%s1.length()]);
					break;
				}
				if(i==s2.length()-1) {
					cout << "Yes" << endl;;
					return 0;
				}		
			}
		}
	}
	cout<<"No"<<endl;
	return 0;
}
