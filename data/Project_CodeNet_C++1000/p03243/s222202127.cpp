#include<bits/stdc++.h>
using namespace std;
bool same(int x){
  	vector<int> v;
  	while(x){
      v.push_back(x%10);
      x/=10;
    }
  	int a=v[0];
  	for(int i=1;i<v.size();i++) if(v[i]!=a) return 0;
  	return 1;
}
signed main(){
  	int n;
  	cin>>n;
  	while(!same(n)) n++;
  	cout<<n;
    return 0;
}