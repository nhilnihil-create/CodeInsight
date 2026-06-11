#include<bits/stdc++.h>
using namespace std;
int n,a,b;
pair<int,int> ar[1005];
bool f(pair<int,int> p){
	return p.first>=a&&p.second>=b;
}
int main(){
	cin>>n>>a>>b;
  	for(int i=1;i<=n;i++){cin>>ar[i].first>>ar[i].second;}
  	cout<<count_if(ar+1,ar+n+1,f);
}