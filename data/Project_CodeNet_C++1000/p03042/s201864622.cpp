#include <bits/stdc++.h>
using namespace std;
#define ll long long;
 
int main(){
  string s;cin>>s;
  int a=(s[0]-'0')*10+(s[1] - '0');
  int b=(s[2] - '0')*10+(s[3] - '0');
  bool flg1=0<a && a<=12;
  bool flg2=0<b && b<=12;
  if(flg1 && flg2) 
		cout<<"AMBIGUOUS"<< endl;
  else if(a == 0 && flg2) 
		cout<<"YYMM"<<endl;
  else if(b == 0 && flg1) 
		cout<<"MMYY"<<endl;
  else if(flg1 && !flg2) 
		cout<<"MMYY"<< endl;
  else if(!flg1 && flg2) 
		cout<<"YYMM"<<endl;
  else cout<<"NA"<<endl;
  return 0;
}