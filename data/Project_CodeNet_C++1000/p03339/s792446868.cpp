#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  string str;
  cin>>N;
  cin>>str;
  vector<int> de(N-1);
  vector<int> dw(N-1);
  dw.at(0)=(str.at(0)=='W'?1:0);
  de.at(0)=(str.at(N-1)=='E'?1:0);
  for(int i=1;i<N-1;i++){
    dw.at(i)=dw.at(i-1)+(str.at(i)=='W'?1:0);
    de.at(i)=de.at(i-1)+(str.at(N-1-i)=='E'?1:0);
  }
  int cnt=de.at(N-2);
  for(int i=1;i<N-1;i++){
    int tmp=de.at(N-2-i)+dw.at(i-1);
    cnt=min(cnt,tmp);
  }
  cnt=min(cnt,dw.at(N-2));
  cout<<cnt<<endl;
}
