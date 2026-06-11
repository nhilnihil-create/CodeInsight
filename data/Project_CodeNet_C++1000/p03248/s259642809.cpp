#include<iostream>
using namespace std;

int main(){
  string s; cin >> s;
  int len=s.size();
  bool flag=(s.at(0)=='1' && s.at(len-1)=='0');
  for(int i=0;i<len-1;i++){
    if(s.at(i)!=s.at(len-2-i))flag=false;
  }
  if(!flag){
    cout << -1 << "\n";
    return 0;
  }
  flag=1;
  int temp=0;
  for(int i=1;i<len;i++){
    printf("%d %d\n",temp+1,i+1);
    if(flag)temp=i;
    if(s.at(i)=='1')flag=1;
    else flag=0;
  }
}
