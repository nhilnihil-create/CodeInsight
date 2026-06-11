#include<bits/stdc++.h>
using namespace std;
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii              pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define PI              3.14159265
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define pw(b,p)         pow(b,p) + 0.1
#define __              ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define rep(i,a,b) 		for(int i=a;i<b;i++)
#define repb(i,a,b) 	for(int i=a;i>=b;i--)
#define endl			"\n"
#define m(a)		    memset(a,0,sizeof(a))
#define all(x)          begin(x), end(x)

/*
// warning this works with cpp14 only...register depricated in 17
void fastscan(int &x){
bool neg = false;register int c;
x = 0;c = getchar();
if(c=='-'){neg = true;c = getchar();}
for(; (c>47 && c<58); c=getchar()){x = x *10 + c - 48;}
if(neg){x *= -1;}}

*/

void file(){
	#ifndef ONLINE_JUDGE
	freopen("in.txt" , "r" , stdin);
	freopen("out.txt" , "w" , stdout);
	#endif
}

int bs(int a[] , int s , int e, int x){
	if(s<=e){
		int m = (s+e)/2;
		if(a[m]==x)
			return m;
		else if(a[m] > x)
			return bs(a,s,m-1,x);
		else return bs(a,m+1,e,x);
	}
	return -1;
}

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr5(v,w,x,y,z) cout<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr6(u,v,w,x,y,z) cout<<u<<" "<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

#define deb(x) cout<<#x<<"="<<x<<endl
#define deb2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<endl
#define deb3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<endl
#define deba(a) for(auto &x:a) cout<<x<<" ";

#define sd(x) cin >> x;
#define sd2(x,y) cin >> x >> y;
#define sd3(x,y,z) cin >> x >> y >> z;
#define sd4(w,x,y,z) cin >> w >> x >> y >> z;

bool is_pal(string s) {return equal(all(s), s.rbegin());}

int fxp(int a, int b ,int p){       //(logn) fast exponentiation
    int res = 1;            		// call int x = fxp(2,5);
    while (b > 0) {
        if (b & 1)
            res = (res * a)%p;
        a = (a * a)%p;
        b >>= 1;
    }
    return (res%p);
}

void solveFrogOne(){
	int n; cin >> n;
	int a[n]; for(int i=0 ; i<n ; ++i) cin >> a[i];
	int dp[n];
	dp[0]=0;
	dp[1] = abs(a[1]-a[0]) + dp[0];
	for(int i=2 ; i<n ; ++i){
		dp[i] = min(dp[i-1] + abs(a[i]-a[i-1]) , dp[i-2] + abs(a[i]-a[i-2]));
	}
	cout << dp[n-1] << endl;
}

void solveFrogTwo(){
	int n,k; cin >> n >> k;
	int a[n]; for(int i=0 ; i<n ; ++i) cin >> a[i];
	int dp[n];
	fill(dp , dp+n , inf);
	dp[0]=0;
	dp[1] = abs(a[1]-a[0]);
	for(int i=2 ; i<n ; ++i){
		for(int j=1 ; j<min(k,i)+1 ; ++j){
			dp[i] = min(dp[i-j]+abs(a[i]-a[i-j]) , dp[i]);
		}
	}
	cout << dp[n-1] << endl;
}

int32_t main(){	
	__;
	file();
	solveFrogTwo();
	return 0;
}




