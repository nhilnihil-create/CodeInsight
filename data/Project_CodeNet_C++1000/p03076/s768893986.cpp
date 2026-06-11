#include <bits/stdc++.h>
using namespace std;

int main() {

  vector<int>a(5);
  int c=0;//端数すべて切り上げの合計数
  int e=0;//%10の余り
  int d=9;//端数の最小値
  int f=0;//%10の余り合計
  for(int i=0;i<5;i++){
  cin>>a.at(i);
    c+=a.at(i);
    e=a.at(i)%10;
    f+=e;
    if(e!=0){//0の場合は省く
    d=min(d,e);
    c-=(a.at(i)%10-10);
    }
  }
  if(f==0){//すべて10の倍数の場合はそのまま足し算
  cout<<c;
  }
  else{
    cout<<c-(10-d);//端数最小値-10が最大短縮
  }
}