#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,x,i;cin>>n;vector<int>v;
  	for(i=1;i<=n;i++){
    	cin>>x;
    	if(x>i) {cout<<-1<<endl;return 0;}
    	v.insert(v.begin()+x-1,x);
  	}
  	for(auto it:v)cout<<it<<endl;
}