#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define fi first
#define se second
//#define mp make_pair
#define pb push_back
typedef pair<int,int> P;
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define abs(x) ((x)>0?(x):-(x))
const int maxn = 100205, inf = 0x3f3f3f3f;
int a,b;
int main(){
	cin>>a>>b;
	if(a+b==15) puts("+");
	else if(a*b==15) puts("*");
	else puts("x");
	return 0;
}