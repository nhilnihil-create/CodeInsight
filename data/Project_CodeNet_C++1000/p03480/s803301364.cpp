#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef pair<ll,ll> p;
const int inf=(1<<30);
#define rep(i,a,n)	for(int i=a;i<n;i++)
#define rrep(i,a,n) for(int i=(a-1);i>=n;i--)
	
bool pairComparesecond(const p& firstElof, const p& secondElof)
{
    return firstElof.second > secondElof.second;
}

int main(){
	string s;
	cin>>s;
	int x=s.size();
	int ans=s.size();
	rep(i,1,s.size()){
		if(s[i-1]!=s[i]){
			ans=min(ans,max(i,x-i));
		}
	}
	cout<<ans<<endl;
}