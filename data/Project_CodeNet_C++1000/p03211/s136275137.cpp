#include<bits/stdc++.h>
using namespace std;
int main(){
  int i;
  string s,s3;
  int num;
  int dlt;
  int dltMin=1000;
  
  cin >> s;
  
  for(i=0;i<s.size()-2;i++){
    s3[0] = s[i];
    s3[1] = s[i+1];
    s3[2] = s[i+2];
    dlt = abs(atoi(s3.c_str()) - 753);
    dltMin = min(dltMin,dlt);
    
  }
  cout << dltMin << endl;
  
}