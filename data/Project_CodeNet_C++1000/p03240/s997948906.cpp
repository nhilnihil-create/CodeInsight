#include <bits/stdc++.h>
using namespace std;


int main() {

  int n;
  cin>>n;


    vector<vector<int>> data(n, vector<int>(3));
    for(int i=0;i<n;i++){
      cin>>data.at(i).at(0)>>data.at(i).at(1)>>data.at(i).at(2);
    }

    int out_cx,out_cy,out_h;
    for(int cx=0;cx<=100;cx++){
      for(int cy=0;cy<=100;cy++){
        bool flg=false;
        int h,x,y,Hwk;
        bool first=true;
        bool second=false;
        for(int i=0;i<n;i++){
          h=data.at(i).at(2);
          x=data.at(i).at(0);
          y=data.at(i).at(1);
          if(first&&h!=0){
            Hwk=h+abs(x-cx)+abs(y-cy);
            first=false;
            second=true;
          }
          if(second){
            if(max(Hwk-abs(x-cx)-abs(y-cy),0)==h&&Hwk>=1){
              if(i==n-1){
                flg=true;
              }
            }else{
              flg=false;
              break;
            }
          }
          }
        if(flg){
          out_cx=cx;
          out_cy=cy;
          out_h=Hwk;
        }
      }
    }

  cout<<out_cx<<" "<<out_cy<<" "<<out_h<<endl;

  return 0;
}


