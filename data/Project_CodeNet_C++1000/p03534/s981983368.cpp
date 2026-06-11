#include <bits/stdc++.h>
#define endre getchar();getchar();return 0
#define INF 1000000007
#define rep(i,n) for(int i=0;i<n;i++)
#define P pair<int,int>
#define prique(T) priority_queue<T,vector<T>,greater<T>>
#define vecunique(vec) sort(vec.begin(), vec.end());decltype(vec)::iterator result = std::unique(vec.begin(), vec.end());vec.erase(result, vec.end())
using namespace std;
string s;
signed main(){
	cin>>s;
	int a=0,b=0,c=0;
	rep(i,s.size()){
		if(s[i]=='a')a++;
		else if(s[i]=='b')b++;
		else c++;
	}
	if((s.size()+2)/3<a)puts("NO");
	else if((s.size()+2)/3<b)puts("NO");
	else if((s.size()+2)/3<c)puts("NO");
	else puts("YES");
	return 0;
}