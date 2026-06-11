#include<bits/stdc++.h>
using namespace std;
int main(){
      // #ifndef ONLINE_JUDGE
      //  // for getting input from input.txt
      //  freopen("input.txt", "r", stdin);
      //  // for writing output to output.txt
      //  freopen("output.txt", "w", stdout);
      // #endif
	int a,b,c=0,d=0;
  	string s;
  	cin>>a>>b;
  	cin>>s;
    // cout<<s.at(a);
  if(s.at(a) == '-'){
    	c++;
    }
    for (int i = 0; i < s.length(); ++i)
    {
      if(!(s.at(i) >='0' && s.at(i) <= '9')){
        d++;
      }
    }
	if(c == 1 && d ==1){ cout<<"Yes"<<"\n"; }
  else { cout<<"No"<<"\n"; }
	return 0;
}
