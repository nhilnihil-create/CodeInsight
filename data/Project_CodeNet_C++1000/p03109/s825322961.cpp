#include <bits/stdc++.h>
using namespace std;
int main(){
  string raw;
  string datastr[3];
  int cnt=0;
  cin >> raw;
  for(int i=0;i<raw.length();i++){
    if(raw[i]=='/'){
      cnt++;
    }else{
      datastr[cnt]=datastr[cnt]+raw[i];
    }
  }
  if(stoi(datastr[0])>2019 || (stoi(datastr[0])==2019 && stoi(datastr[1])>4 )){
    cout << "TBD";
  }else{
    cout << "Heisei";
  }
  return 0;
}