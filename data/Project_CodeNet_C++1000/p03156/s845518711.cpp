#include<bits/stdc++.h>
using namespace std;
int n,aa,bb,tmp;
vector<int> a,b,c;
int main(){
	cin>>n>>aa>>bb;
  	for(int i=1;i<=n;i++){
      cin>>tmp;
      if(tmp<=aa){
      	a.push_back(tmp);
      }
      else if(tmp<=bb){
      	b.push_back(tmp);
      }
      else {
      	c.push_back(tmp);
      }
    }
  	cout<<min({a.size(),b.size(),c.size()});
}