#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define mem(x,n) memset(x,n,sizeof(x))
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define foreach(it,l) for(auto it=(l).begin();it!=(l).end();it++)
#define pnl printf("\n")
#define len(x) (x).length()

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
const double EPS=1e-10;
//const double PI=acos(-1.0);
const int INF=1<<30;
const LL LLINF=1ll<<60;
const int MOD=1e9+7;
const int xx[8]={1,0,-1,0,1,-1,1,-1};
const int yy[8]={0,1,0,-1,-1,1,1,-1};

/****************************************************************************************\
 __    __               __ /\/|   ___ _           _       /\/|__               __    __
 \ \  / /  _____ __ ____\ \/\/   / __| |__ _ _ __(_)___  |/\// /____ __ _____  \ \  / /
  \ \| |  |___\ V  V /___| |    | (__| / _` | '_ \ / -_)    | |___\ V  V /___|  | |/ /
   \_\ |  |___|\_/\_/|___| |     \___|_\__,_| .__/_\___|    | |___|\_/\_/|___|  | /_/
      \_\               /_/                 |_|              \_\               /_/
\****************************************************************************************/

bool cek(string a,string b){
	return a==b;
}

int main(){
	string s;
	cin>>s;
	
	if(	cek(s,"AKIHABARA")
		||cek(s,"AKIHABAR")||cek(s,"AKIHABRA")||cek(s,"AKIHBARA")||cek(s,"KIHABARA")
		||cek(s,"AKIHABR")||cek(s,"AKIHBAR")||cek(s,"KIHABAR")||cek(s,"AKIHBRA")||cek(s,"KIHABRA")||cek(s,"KIHBARA")
		||cek(s,"AKIHBR")||cek(s,"KIHABR")||cek(s,"KIHBRA")||cek(s,"KIHBAR")
		||cek(s,"KIHBR")){
			printf("YES\n");
		}
		else printf("NO\n");
}