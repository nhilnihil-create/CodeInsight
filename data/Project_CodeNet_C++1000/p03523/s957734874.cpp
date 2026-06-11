#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define fr front()
#define tp top()
typedef long long int ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <pii, int> ppi;
typedef pair <int, pii> pip;
#define iofast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define iofile freopen("input.txt","r",stdin),freopen("output.txt","w",stdout)
const ll LLINF = 1e18;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const double EPS = 1e-10;
const double PI = acos(-1);
const int SIZE = 100005;

string S;
string Akiba="AKIHABARA";
string lel="KIHBR";
int cnt[26];

int main (){
	
	iofast;
	memset(cnt,0,sizeof(cnt));
	
	cin>>S;
	int n=S.size();
	int m=Akiba.size();
	for(int i=0;i<n;i++){
		cnt[S[i]-'A']++;
	}
	bool valid=true;
	if(n==m){
		for(int i=0;i<n;i++){
			if(S[i]!=Akiba[i]) valid=false;
		}
	} else if(n>m){
		valid=false;
	} else if(n<m){
		for(int i=0;i<(int)lel.size();i++){
			if(cnt[lel[i]-'A']!=1) valid=false;
		}
		if(valid==true){
			valid=false;
			int indx=0;
			for(int i=0;i<m;i++){
				if(indx==n){
					valid=true;
					break;
				}
				if(S[indx]==Akiba[i]){
					indx++;
				}
			}
			if(indx==n) valid=true;
		}
	}
	if(valid==true) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	
	
	return 0;
}