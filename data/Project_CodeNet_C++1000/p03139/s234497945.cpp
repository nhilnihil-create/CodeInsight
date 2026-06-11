#include "bits/stdc++.h"
#define inf 0x3f3f3f3f
#define pb push_back
#define vi vector<int>
#define fi first
#define se second 
#define mp make_pair
typedef unsigned long long ull;
//typedef pair<int,int> P;
#define LL long long 
#define pi acos(-1)
#define MOD 998244353
typedef long long ll;
using namespace std;
const int maxn = 19995; 
const char p[]="AGC";
int main(){
	int n,a,b;
	cin>>n>>a>>b;
	cout<<min(a,b)<<' '<<max(0,a+b-n)<<endl;
	return 0;
}
