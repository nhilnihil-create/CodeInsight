//finally if there is any zero close to a 1 one , I can still remove it
//Let's say you keep on removing numbers at some stage you run out of zeroes or ones
//so answer is min of both * 2
#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
  cin>>s;
  int ones=0;
  int zeros=0;
  for(int i=0;i<s.length();i++){
  	if(s[i]=='1')ones++;
    else zeros++;
  }
  cout<<min(ones,zeros)*2;
}