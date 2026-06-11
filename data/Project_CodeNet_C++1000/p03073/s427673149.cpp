#include<bits/stdc++.h>
using namespace std;
      
int main(){
  string S;
  cin >> S;
  int N=S.size();
  int count1=0,count2=0;
  for(int i=0;i<N;i++){
    if(i%2==0 && S.at(i)=='0'){
      count1++;
    }
    else if(i%2==1 && S.at(i)=='1'){
      count1++;
    }
    if(i%2==0 && S.at(i)=='1'){
      count2++;
    }
    else if(i%2==1 && S.at(i)=='0'){
      count2++;
    }
  }
  cout << min(count1,count2) << endl;
}
    