#include <bits/stdc++.h>
using namespace std;
 
int main() {
    string S;
    cin >>S;
    int count0=0;
    int count1=0;
    for(int i=0;i<S.size();i++){
      if(S.at(i)=='0'){
          count0++;
      }
      else if(S.at(i)=='1'){
          count1++;
      }
    }
    int aaa=min(count0,count1);
    cout <<aaa*2<<endl;
}