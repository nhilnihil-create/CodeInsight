#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for(int i=0;i<(int)n;i++)
#define PI acos(-1)
#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);
ll mod=1e9+7;


int main(){
    fast_io

    string s;
    cin>>s;
    string key = "keyence";
	if(s == key){
		puts("YES");
		return 0;
	}
	int n = s.size();
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			//delete [i,j]
			string S = "";
			for(int k=0;k<n;k++){
				if(i<=k && k<=j){
					continue;
				}
				else S.push_back(s[k]);
			}
			if(S == key){
				puts("YES");
				return 0;
			}
		}
	}
	puts("NO");
    
    return 0;
}
