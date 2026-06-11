#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c,d;
  	set<int> s;
  	cin>>a>>b>>c>>d;
  	s.insert(a);s.insert(b);s.insert(c);s.insert(d);
  	if(s.count(1)&&s.count(9)&&s.count(7)&&s.count(4)) cout<<"YES";
  	else cout<<"NO";
}