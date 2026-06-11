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
int n;
char s[maxn];
int main(){
	cin>>s>>n;
	int m=strlen(s);
	for(int i=0;i<m;i++){
		if((i)%n==0) {
			cout<<s[i];
		}
	}
	return 0;
}