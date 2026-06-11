#include <bits/stdc++.h>

using namespace std;

int main() {
  int h;
  cin>>h;
  vector<int> vec(4);
  vec[0]=h%10;
  h/=10;
  vec[1]=h%10;
  h/=10;
  vec[2]=h%10;
  vec[3]=h/10;
  for(int tmp=0;tmp<8;tmp++){
    bitset<3> s(tmp);
    int x=vec[3];
    for(int i=0;i<3;i++){
      if(s[i]==0){
        x+=vec[2-i];
      }
      else{
        x-=vec[2-i];
      }
    }
    if(x==7){
      cout<<vec[3];
      for(int i=0;i<3;i++){
        
        if(s[i]==0){
        cout<<'+';
      }
        else{
        cout<<'-';;
      }
        cout<<vec[2-i];
      }
      cout<<"=7"<<endl;
      return 0;
    }
  }
    
    
  
}
