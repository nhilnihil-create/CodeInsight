#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin >> s;
  if(s=="abc"||s=="acb"||s=="bac"||s=="bca"||s=="cab"||s=="cba"){
    printf("Yes");
  }
  else{
    printf("No");
  }
}
