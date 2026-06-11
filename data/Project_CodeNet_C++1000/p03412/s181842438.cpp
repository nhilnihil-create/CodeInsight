#include <iostream>
#include <iomanip>
#include <ios> 
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <bitset>
#include <map>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define sz(c) ((int)(c).size())

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
//const int MAX=;



int main(){
	int N;
	cin>>N;
	vi a(N,0),b(N,0);
	rep(i,N)cin>>a[i];
	rep(i,N)cin>>b[i];
	
	
	int ans=0;
	for(int k=28;k>=0;k--){
		int ca=0,cb=0;
		rep(i,N){
			if(a[i]>=(1<<k)){
				ca++;
				a[i]-=(1<<k);
			}
		}
		rep(i,N){
			if(b[i]>=(1<<k)){
				cb++;
				b[i]-=(1<<k);
			}
		}
//      	cout<<ca<<" "<<cb<<endl;
      	ca=ca%2;cb=cb%2;
		int fl=ca*((N%2)+2-cb)%2+cb*((N%2)+2-ca)%2;

      	if(k!=0){
			sort(a.begin(),a.end());
			rep(i,N){
				int d=lower_bound(a.begin(),a.end(),(1<<k)-b[i])-a.begin();
				fl+=(N-d)%2;
			};
        }
		fl=fl%2;
		ans+=(fl << k);
	}
	cout<<ans<<endl;
}