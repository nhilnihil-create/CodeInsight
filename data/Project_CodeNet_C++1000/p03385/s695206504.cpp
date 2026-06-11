#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin >> s;
  int count_1=0,count_2=0,count_3=0;
  int i;
  for(i=0;i<3;i++){
    if(s.at(i)=='a'){
      count_1++;
    }
    if(s.at(i)=='b'){
      count_2++;
    }
    if(s.at(i)=='c'){
      count_3++;
    }
  }
  if(count_1==count_2 && count_1==count_3){
	cout << "Yes";
  }else{
    cout << "No";
  }
}