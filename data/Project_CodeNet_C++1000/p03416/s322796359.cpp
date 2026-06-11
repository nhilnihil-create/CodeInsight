#include <bits/stdc++.h>
#define PI 3.1415926535897932
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  int A,B;
  cin>>A>>B;
  
  vector<int> check(90000);
  for(int i=0;i<90000;i++){
    check[i]=i+10000;
    string num=to_string(check[i]);
    char a_1,a_2,a_4,a_5;
    a_1=num[0];
    a_2=num[1];
    a_4=num[3];
    a_5=num[4];
    if(a_1!=a_5||a_2!=a_4){
      check[i]=0;
    }
  }
  
  int ans=0;
  
  
  for(int i=0;i<90000;i++){
    if(A<=check[i]&&check[i]<=B){
      ans++;
    }
  }
  
  cout<<ans<<endl;
}