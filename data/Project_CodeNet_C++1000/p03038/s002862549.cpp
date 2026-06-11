#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
void solve(vector<int>&arr){
	long long ret = 0;
	for(int i=0; i<arr.size(); i++) ret+=arr[i];
	cout<<ret;
}
int main(){
	int n,m;
	cin>>n>>m;
	vector<int>arr(n);
	for(int i=0; i<n; i++) cin>>arr[i];
	vector<pi>op(m);
	for(int i=0; i<m; i++) cin>>op[i].second>>op[i].first;
	sort(arr.begin(),arr.end());
	sort(op.begin(),op.end());
	int p = 0;
	reverse(op.begin(),op.end());
	for(int i=0; i<op.size(); i++){
		int change_to = op[i].first;
		int change_num = op[i].second;
		while(p<arr.size() && change_num){
			if(arr[p]<change_to) arr[p] = change_to;
			else break;
			p++;
			change_num--;
		}
	}
	solve(arr);
}