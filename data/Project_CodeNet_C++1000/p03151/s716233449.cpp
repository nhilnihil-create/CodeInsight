#include <bits/stdc++.h>
using namespace std;
long long cnt,sum,a[200005],b[200005];
vector<int> c;
#define rep(i,n) for(int i = 0; i < n;i++)
int main(){
	int n;cin>>n;
	rep(i,n) cin>>a[i];
	rep(i,n){
        cin >> b[i];
		if(a[i]>=b[i])c.push_back(a[i]-b[i]);
		else{
			sum+=(b[i]-a[i]);cnt++;
		}
	}
	sort(c.rbegin(),c.rend());
	rep(i,c.size()){
		if(sum>0) {
          sum-=c[i];cnt++;
		}
	}
	if(sum>0)cnt=-1;
	cout<<cnt;
}