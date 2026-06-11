#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <cstring>
#include <cassert>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <cmath>
#include <set>
#include <map>
#include <functional>

using namespace std;
#define     loop(n,i,a)     for(int i=a;i<n;i++)
#define     all(arr,n)      arr,arr+n
#define     allv(v)         (v).begin(),(v).end()
#define     rallv(v)        (v).rbegin(),(v).rend()
#define     m_p             make_pair
#define     ll              long long
#define     vi              vector<int>
#define     vll             vector<ll>
#define     sz(x)           (int)x.size()
#define     pb              push_back
int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
ll power(ll x, ll y)
{
    ll temp;
    if( y == 0)
        return 1;
    temp = power(x, y/2);
    if (y%2 == 0)
        return temp*temp;
    else
        return x*temp*temp;
}
const int N=55;
int arr[N];
int main() {
	int n,mn=0,mx=0,cntp=0,cntn=0,idn=-1,idp=-1;cin>>n;
	loop(n,i,0){
		cin>>arr[i];
		cntp+=(arr[i]>0);
		cntn+=(arr[i]<0);
		if(mn>arr[i]){
			mn=arr[i];
			idn=i;

		}
		if(mx<arr[i]){
			mx=arr[i];
			idp=i;
		}
	}
	vector<pair<int,int>>v;
//	cout<<idp<<' '<<idn<<endl;
	if(abs(mn)>mx||cntp==0){
		if(idn==-1)idn=0;
		loop(n,i,0){
			if(idn==i)continue;
			if(arr[i]>=0)
				v.pb({idn+1,i+1});
		}
		for(int i=n;i>1;i--){
			v.pb({i,i-1});
		}
	}
	else{
		if(idp==-1)idp=0;
		loop(n,i,0){
			if(i==idp)continue;
			if(arr[i]<=0)
			v.pb({idp+1,i+1});
		}
		loop(n-1,i,0)
			v.pb({i+1,i+2});
	}
	cout<<sz(v)<<endl;
	for(auto z:v)cout<<z.first<<' '<<z.second<<endl;
}
