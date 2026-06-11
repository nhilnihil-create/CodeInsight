#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define FOR(i,a,b) for(int i=(a); i<=(b); i++)
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define chmin(a,b) if((a)>(b)) (a)=(b);
#define chmax(a,b) if((a)<(b)) (a)=(b);
#define vi vector<int>
#define pii pair<int,int>
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define pb push_back
#define pf push_front
int gcd(int a,int b){/*a>=0,b>=0,￢(a=b=0)*/
  while(min(a,b)>0){if(a<b)swap(a,b);a%=b;}return max(a,b);
}
int dx[]={1,0,-1,0,1,-1,-1,1};
int dy[]={0,1,0,-1,1,1,-1,-1};
const int MOD = 1e9+7;
const long long INF = 1e18+10;

/*--------------------------------------------------------------------*/

signed main(){
	int n;cin>>n;
	int cnt=0,a=0,b=0,ab=0;
	rep(i,n){
		string s;
		cin>>s;
		if(s.front()=='B'&&s.back()=='A')ab++;
		else{
			if(s[0]=='B')b++;
			if(s[s.size()-1]=='A')a++;
		}
		
		rep(j,s.size()-1){
			if(s[j]=='A'&&s[j+1]=='B')cnt++;
		}
	}

	if(a==0&&b==0){
		cout<<cnt+max(0ll,ab-1)<<endl;
	}else if(b==0||a==0){
		cout<<cnt+ab<<endl;
	}else if(ab==0){
		cout<<cnt+min(a,b)<<endl;
	}else{
		int k=min(a,b);
		cnt+=k;
		a-=k;
		b-=k;
		cout<<cnt+ab<<endl;
	}
	
	return 0;
}
