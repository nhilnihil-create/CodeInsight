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
const ll MOD=1e6+3;


int main(){
	int N;
	cin>>N;
	
	int A[2005];
	int s=0;
	rep(i,N){
		cin>>A[i];
		s+=A[i];
	}
	int h=(s+1)/2;
	
	bitset<4000005> b;
	b |= 1;
	rep(i,N){
		b |= (b<<A[i]);
	}
	int ans=h;
	while(true){
		if(b[ans]){
			break;
		}
		ans++;
	}
	cout<<ans<<endl;
}