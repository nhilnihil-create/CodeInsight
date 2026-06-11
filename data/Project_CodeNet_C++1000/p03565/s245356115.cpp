#include <set>
#include <bitset>
#include <queue>
#include <deque>
#include <set>
#include <bitset>
#include <queue>
#include <deque>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
 
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <string>
#include <cassert>
 
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
using namespace std;
#define f(i,a,b) for(int (i)=int(a);i<=int (b);i++)
#define ff(i,a,b) for(int (i)=int (a);i<int (b);i++)
#define F(i,a,b) for(int (i)=int (a);i>=int (b);i--)
#define fi first
#define se second
#define ll long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
const int inf=1<<30,mod=1e9+7,N=1e6+7;
string s,t;
int main(){
	cin>>s>>t;
	int n=s.size(),m=t.size();
	F(i,n-m,0){
		string v=s.substr(0,i),u=s.substr(i,m),z=s.substr(i+m);
		bool check=1;
		ff(j,0,m){
			if(t[j]==u[j]||u[j]=='?') continue;
			else check=0;
		}
		if(check){
			ff(k,0,v.size()) {
				if(v[k]=='?') cout<<"a";
				else cout<<v[k];
			}
			cout<<t;
			ff(k,0,z.size()) {
				if(z[k]=='?') cout<<"a";
				else cout<<z[k];
			}
			return 0;
		}
	}
	cout<<"UNRESTORABLE";
}