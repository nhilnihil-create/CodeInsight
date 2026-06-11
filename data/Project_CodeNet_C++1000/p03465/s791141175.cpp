//* aman*/
#include<bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define dl          double
#define hell        1000000007
#define endl        '\n'
#define rep(i,a,b) for(int i=a;i<b;i++)
#define lb lower_bound
#define ub upper_bound
#define bs          binary_search
#define ios         ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
int main(){
	ios;
	int n;cin>>n;
	bitset<5000000> bit;
	bit.set(0);
	vector<int> v(n);
	int sum=0;
	for(int i=0;i<n;i++){
		cin>>v[i];
		bit=bit|(bit<<v[i]);
		sum+=v[i];
	}
	set<int> si;
	for(int i=0;i<=sum;i++){
		if(bit[i]){
			si.insert(i);
		}
	}
	cout<<*si.lower_bound(sum/2+sum%2)<<endl;
}