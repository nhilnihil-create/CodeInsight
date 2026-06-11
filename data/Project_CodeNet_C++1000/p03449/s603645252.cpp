// DANG's code //
// LOVEPAL3000 //
//#pragma 03
//#pragma GCC optimize("Os")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
//#include <boost/multiprecision/cpp_int.hpp>
//using boost::multiprecision::cpp_int;
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef vector<string> vs;
typedef vector<char> vc;
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
#define lo long
#define ll long long
#define fl float
#define db double;
#define ld long double
#define FORE(i,l,r) for(int i=l;i<=r;++i)
#define BACK(i,l,r) for(int i=l;i>=r;--i)
#define fi first
#define se second
#define fr front()
#define ba back()
#define top top()
#define lb lower_bound
#define ub upper_bound
#define pu push
#define pb push_back
#define eb emplace_back
#define ef emplace_front
#define mp make_pair
#define em empty()
#define sz size()
#define le length()
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
int n,a[3][101],dp[3][101];
signed main(){
	cin>>n;
	FORE(i,1,2){
		FORE(j,1,n){
			cin>>a[i][j];
		}
	}
	FORE(i,1,2){
		FORE(j,1,n){
			if(i==1&&j==1){
				dp[i][j]=a[i][j];
			}
			else if(i==1){
				dp[i][j]=dp[i][j-1]+a[i][j];
			}
			else if(j==1){
				dp[i][j]=dp[i-1][j]+a[i][j];
			}
			else{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1])+a[i][j];
			}
		}
	}
	cout<<dp[2][n];
}