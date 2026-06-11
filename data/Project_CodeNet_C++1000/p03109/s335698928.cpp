#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).end()
#define Red ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define rep(i, n) for(int i =0 ; i < n; ++i)
#define Rep(i,a,b) for(int i=a;i<=b;i++)
#define pii pair < int, int >
typedef vector<int> vi;
typedef  long long ll;
const int mod =1e9+7;
const int N = (int)2e5 + 5;

int get(char c){
	return (int)(c-'0');
}

void solve(){
 	string s;
 	cin>>s;
 	int y=get(s[0])*1000+get(s[1])*100+get(s[2])*10+get(s[3]);
 	int m=get(s[5])*10+get(s[6]);
 	int d=get(s[8])*10+get(s[9]);
 	if(y>2019){
 		cout<<"TBD";
 		return;
 	}	
 	if(y<2019){
 		cout<<"Heisei";
 		return;
 	}		
 	if(m<4){
 		cout<<"Heisei";
 		return;
 	}
 	if(m>4){
 		cout<<"TBD";
 		return;
 	}
 	if(d<=30){
 		cout<<"Heisei";
 		return;
 	}
 	cout<<"TBD";
	
    
}

int main(){
	Red;
	int t=1;
	//cin>>t;
	while(t--)
	solve();
	return 0;
}