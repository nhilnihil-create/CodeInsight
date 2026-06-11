#include<bits/stdc++.h>
using namespace std;

typedef long long llint;
typedef long double ld;

#define inf 1e18
#define mod 1000000007
priority_queue<llint,vector<llint>,greater<llint> > que;
priority_queue<llint> Que;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

void solve(){
    vector<int>a(5);
    for(int i=0;i<5;i++)cin >> a[i];
    int mxdif=0;
    int mndif=1e9;
    int mxidx=-1;
    int ans=0;
    for(int i=0;i<5;i++){
		if(a[i]%10==0) ans+=a[i];
		else ans+=((10-(a[i]%10))+a[i]);
 
		if(10-a[i]%10>mxdif && a[i]%10!=0){
			mxdif=10-a[i]%10;
			mxidx=i;
		}
	}
    if(mxidx!=-1){
		ans-=(10-(a[mxidx]%10))+a[mxidx];
		ans+=a[mxidx];
 
	}
	cout << ans << endl;

}

int main(){
  solve();
  return 0;
}
