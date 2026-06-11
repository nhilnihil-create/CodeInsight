#include<iostream>
#include<string>
using namespace std;

int main(){
  string s;
  int i;
  int count=0;
  cin >> s[0] >> s[1] >> s[2];
  for(i=0;i<3;i++){
  	if(s[i]=='o'){
    	count++;
    }
  }
  cout << 700+(100*count) << endl;
  
  return 0;
}