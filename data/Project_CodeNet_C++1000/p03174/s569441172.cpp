#include<bits/stdc++.h>

#define X first
#define Y second
#define ll long long
#define MP make_pair
#define PB push_back

using namespace std;

const int MAXN=1e5;
ll MOD=1e9+7;

ll dp[4194307];
ll n,mat[25][25];
string s;
ll pot=1;
ll pom,br;
vector <ll> cije[25];

int main () {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin>>n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>mat[i][j];
		}
		pot*=2;
	}
	dp[pot-1]=1;
	for(int j=0; j<pot; j++){
		pom=j;
		br=0;
		while(pom>0){
			br+=(pom%2);
			pom/=2;
		}
		cije[n-br].PB(j);
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<cije[i].size(); j++){
			pom=cije[i][j];
			s="";
			while(pom>0){
				s+=('0'+(pom%2));
				pom/=2;
			}
			while(s.size()<n){
				s+='0';
			}
			pom=cije[i][j];
			for(int k=0; k<n; k++){
				if(mat[i][k]==1 && s[k]=='1'){
					dp[pom-(1<<k)]+=dp[pom];
					dp[pom-(1<<k)]%=MOD;
				}
			}
		}
	}
	cout<<dp[0];
	
	return 0;
}