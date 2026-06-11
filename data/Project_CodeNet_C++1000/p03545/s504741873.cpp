#include<bits/stdc++.h>
using namespace std;

int main(){
  string str;
  cin>>str;
  int a,b,c,d,t;
  t=stoi(str);
  a=t/1000;t-=a*1000;
  b=t/100;t-=b*100;
  c=t/10;t-=c*10;
  d=t;
  
  vector<int> B={1,1,1,1,-1,-1,-1,-1};
  vector<int> C={1,1,-1,-1,1,1,-1,-1};
  vector<int> D={1,-1,1,-1,1,-1,1,-1};
  for(int i=0;i<8;i++){
    int tmp=a+b*B.at(i)+c*C.at(i)+d*D.at(i);
    if(tmp==7){
      cout<<a;
      cout<<(B.at(i)==1?'+':'-');
      cout<<b;
      cout<<(C.at(i)==1?'+':'-');
      cout<<c;
      cout<<(D.at(i)==1?'+':'-');
      cout<<d;
      cout<<"=7"<<endl;
      break;
    }
  }
}
