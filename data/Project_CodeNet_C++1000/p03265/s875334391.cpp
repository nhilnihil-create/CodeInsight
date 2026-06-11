#include <bits/stdc++.h>
using namespace std;

int main(){
  int x1,x2,y1,y2;cin>>x1>>y1>>x2>>y2;
  int tmp_x,tmp_y;
  tmp_x=x2-x1;
  tmp_y=y2-y1;
  //cout <<tmp_x<<' '<<tmp_y<<endl;;
  cout <<x2-tmp_y<<' '<<y2+tmp_x<<' ';
  cout <<x1-tmp_y<<' '<<y1+tmp_x<<endl;
}