#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  int s1,s2,s3,s4;
  
  cin >> n;
  
  s4=n%10;
  s3=(n/10)%10;
  s2=(n/100)%10;
  s1=n/1000;
  
  if(((s1==s2)&&(s2==s3))||((s2==s3)&&(s3==s4))){
    cout<< "Yes"<<endl;
  }
  
  else{
  cout << "No"<< endl;
  }
  
}