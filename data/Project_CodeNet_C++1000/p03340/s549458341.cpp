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
#include <bitset>

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

int main() {
	int n;cin>>n;
	int arr[n+1],cum[n+1]={},Xo[n+1]={};
	loop(n+1,i,1){
		cin>>arr[i];
		if(!i)
			cum[i]=arr[i],Xo[i]=arr[i];
		else{
			cum[i]=cum[i-1]+arr[i];
			Xo[i]=(Xo[i-1]^arr[i]);
		}
	}
	ll res=0;
	loop(n+1,i,1){
		int l=i,r=n,len=i;
		while(l<=r){
			int mid=(l+r)/2;
			if(cum[mid]-cum[i-1]==(Xo[mid]^Xo[i-1])){
				len=mid;
				l=mid+1;
			}
			else r=mid-1;
		}
		res+=(len-i+1);
	}
	cout<<res<<endl;
}
