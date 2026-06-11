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
const int MAX=2005;
const int INF=1e9+50;


int main(){
	int N,K,Q;
	cin>>N>>K>>Q;
	int A[MAX];
	set<int> st;
	rep(i,N){
		cin>>A[i];
		st.insert(A[i]);
	}
	A[N]=0;
	
	int ans=INF;
	
	for(auto it=st.begin(); it != st.end(); ++it){
		int k=*it;
		vi ca;
		vi v;
		rep(i,N+1){
			if(A[i]>=k)v.push_back(A[i]);
			else{
				if(sz(v)>=K){
					sort(v.begin(), v.end());
					rep(i,sz(v)-K+1)ca.push_back(v[i]);
				}
				v.clear();
			}
		}
		if(sz(ca)>=Q){
			sort(ca.begin(), ca.end());
			ans=min(ans, ca[Q-1]-k);
		}
		else break;
	}
	cout<<ans<<endl;
}