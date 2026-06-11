#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
string str;
string target = "keyence";
int main(){
	cin>>str;
	if(str == target){
		puts("YES");
		return 0;
	}
	int n = str.size();
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			//delete [i,j]
			string S = "";
			for(int k=0;k<n;k++){
				if(i<=k && k<=j){
					continue;
				}
				else S.push_back(str[k]);
			}
			if(S == target){
				puts("YES");
				return 0;
			}
		}
	}
	puts("NO");
}