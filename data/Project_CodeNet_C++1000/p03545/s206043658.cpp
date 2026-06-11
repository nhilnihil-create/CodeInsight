#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;
  int N = S.size();
  for (int s = 0; s < (1 << (N - 1)); s++){
    bitset<5> d(s);
    int sum=S.at(0)-'0';
    vector<char> vec(3);
    for(int i=0;i<3;i++){
      if(d.test(i)){
        sum+=S.at(3-i)-'0';
        vec.at(2-i)='+';
      }
      else{
        sum-=S.at(3-i)-'0';
        vec.at(2-i)='-';
      }
    }
    if(sum==7){
      cout<<S.at(0)<<vec.at(0)<<S.at(1)<<vec.at(1)<<S.at(2)<<vec.at(2)<<S.at(3)<<"=7"<<endl;
      return 0;
    }
    
  }
}