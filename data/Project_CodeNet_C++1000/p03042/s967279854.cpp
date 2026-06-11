#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  int cnt1=0,cnt2=0;
  int num1=(s[0]-'0')*10+s[1]-'0';
  int num2=(s[2]-'0')*10+s[3]-'0';
  if(num1>0 && num1<13)cnt1++;
  if(num2>0 && num2<13)cnt2++;
  if(cnt1==0 && cnt2==0)	cout<<"NA"<<endl;
  else if(cnt1==1 && cnt2==0)	cout<<"MMYY"<<endl;
  else if(cnt2==1 && cnt1==0) cout<<"YYMM"<<endl;
  else	cout<<"AMBIGUOUS"<<endl;
  return 0
    ;
}
