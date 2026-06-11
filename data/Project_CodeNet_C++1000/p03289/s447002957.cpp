#include <bits/stdc++.h>
#include <math.h>
using namespace std;


int main() {
  string s ;
  cin >> s ;
  
  int n=s.size();
  int c=0;
  int d=0;
  for(int i=0;i<n;i++){
    if(i==0){
      if(s.at(i)!='A'){
        cout <<"WA" << endl;
        break;
      }
    }
    
    if(i==1){
      if(s.at(i)<97||s.at(i)>122){
        cout << "WA" <<endl;
        break;
      }
    }
    if(i>1&&i<n-1){
      if(s.at(i)>=97&&s.at(i)<=122){
        c++;
      }
      if(s.at(i)=='C'){
        d++;
      }
    }
    if(i==n-1){
      if(s.at(i)<97||s.at(i)>122){
        cout << "WA" <<endl;
        break;
      }
      if(s.at(i)>=97&&s.at(i)<=122&&c==n-4&&d==1){
        cout << "AC"<< endl;
      }
      else{
        cout << "WA" <<endl;
      }
    }
  }
}
      
    