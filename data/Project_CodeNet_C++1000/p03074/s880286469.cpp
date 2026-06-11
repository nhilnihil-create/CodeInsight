#include<bits/stdc++.h>
using namespace std;
int psum[300005];
int k_psum[300005];
int arr[300005];

int main(){
	int n,k;
	string s;
	cin>>n>>k>>s;
	char curr = s[0];
	int counter = 0;
	vector<int>ret;
	for(int i=0; s[i]; i++){
		if(s[i]==curr) counter++;
		else{
			if(curr=='0') ret.push_back(counter*-1);
			else ret.push_back(counter);
			curr = s[i];
			counter = 1;
		}
	}
	if(curr=='0') ret.push_back(counter*-1);
	else ret.push_back(counter);
	n=ret.size();
	for(int i=0; i<ret.size(); i++) arr[i+1] = ret[i];
	for(int i=1; i<=n; i++){
		if(arr[i]<0) k_psum[i]++;
		k_psum[i]+=k_psum[i-1];
	}
	k_psum[n+1] = 1000000;
	for(int i=1; i<=n; i++){
		psum[i] = abs(arr[i]);
		psum[i]+=psum[i-1];
	}
	psum[n+1] = psum[n];
	int maxget=0;
	for(int i=1; i<=n; i++){
		int direction = k_psum[i-1]+k;
		int index = (upper_bound(k_psum,k_psum+n+2,direction)-k_psum);
		maxget = max(maxget,psum[index-1]-psum[i-1]);
	}
	cout<<maxget;
}