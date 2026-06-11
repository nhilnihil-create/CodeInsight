#include<iostream>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<map>
#include<iomanip>
#include<sstream>
#include<vector>
#include<stack>
#include<math.h>
#include<queue>
#include<complex>
#include<random>
#include<ctime>
#include<set>
using namespace std;


const long long int mod=1000000007;
const long long int INF=99999999999999999;

long long int n,q,l,r;
char d[200005],t[200005];
string s;

int main() {
	cout << fixed << setprecision(18);
	cin>>n>>q>>s;
	for(int i=0;i<q;i++){
		cin>>t[i]>>d[i];
	}
	//左端
	long long int ng=-1,ok=n,mid=(ng+ok)/2;
	while(ok-ng>1){
		long long int now=mid;
		for(int i=0;i<q;i++){
			if(s[now]==t[i]){
				if(d[i]=='R'){now++;}
				else{now--;}
			}
			if(now<0){ng=mid;}
		}
		if(ng!=mid){ok=mid;}
		mid=(ng+ok)/2;
	}
	l=ok;

	ng=-1,ok=n,mid=(ng+ok)/2;
	while(ok-ng>1){
		long long int now=mid;
		for(int i=0;i<q;i++){
			if(s[now]==t[i]){
				if(d[i]=='R'){now++;}
				else{now--;}
			}
			if(now>=n){ok=mid;}
		}
		if(ok!=mid){ng=mid;}
		mid=(ok+ng)/2;
	}
	r=ng;
	cout<<max(r-l+1,0LL);
} 