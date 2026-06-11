#include <bits/stdc++.h>
using namespace std;


int main() {

    int n1,n2,n3,n4;
    cin>>n1>>n2>>n3>>n4;

    int cnt1=0,cnt9=0,cnt7=0,cnt4=0;

   if(n1==1)
      cnt1++;
    else if(n1==9)
      cnt9++;
    else if(n1==7)
      cnt7++;
    else if(n1==4)
      cnt4++;

   if(n2==1)
      cnt1++;
    else if(n2==9)
      cnt9++;
    else if(n2==7)
      cnt7++;
    else if(n2==4)
      cnt4++;

   if(n3==1)
      cnt1++;
    else if(n3==9)
      cnt9++;
    else if(n3==7)
      cnt7++;
    else if(n3==4)
      cnt4++;

   if(n4==1)
      cnt1++;
    else if(n4==9)
      cnt9++;
    else if(n4==7)
      cnt7++;
    else if(n4==4)
      cnt4++;

  if(cnt1==1&&cnt9==1&&cnt7==1&&cnt4==1)
    cout<<"YES"<<endl;
  else
  {
    cout<<"NO"<<endl;
  }
  


    return 0;
}
