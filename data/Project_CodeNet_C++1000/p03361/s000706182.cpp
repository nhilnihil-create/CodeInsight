#include<bits/stdc++.h>
using namespace std;
int main(){
  int h,w,i,j;
  string ans="Yes";
  cin>>h>>w;
  vector<string> s(h);
  for(i=0;i<h;i++) cin>>s.at(i);
  for(i=0;i<h;i++){
    for(j=0;j<w;j++){
      if(s.at(i).at(j)=='#'){
        if(0<i&&i<h-1&&0<j&&j<w-1&&s.at(i-1).at(j)=='.'&&s.at(i).at(j-1)=='.'&&s.at(i).at(j+1)=='.'&&s.at(i+1).at(j)=='.') ans="No";
        else if(0==i&&0<j&&j<w-1&&s.at(i).at(j-1)=='.'&&s.at(i).at(j+1)=='.'&&s.at(i+1).at(j)=='.') ans="No";
        else if(i==h-1&&0<j&&j<w-1&&s.at(i-1).at(j)=='.'&&s.at(i).at(j-1)=='.'&&s.at(i).at(j+1)=='.') ans="No";
        else if(0<i&&i<h-1&&0==j&&s.at(i-1).at(j)=='.'&&s.at(i).at(j+1)=='.'&&s.at(i+1).at(j)=='.') ans="No";
        else if(0<i&&i<h-1&&j==w-1&&s.at(i-1).at(j)=='.'&&s.at(i).at(j-1)=='.'&&s.at(i+1).at(j)=='.') ans="No";
        else if(0==i&&0==j&&s.at(i).at(j+1)=='.'&&s.at(i+1).at(j)=='.') ans="No";
        else if(0==i&&j==w-1&&s.at(i).at(j-1)=='.'&&s.at(i+1).at(j)=='.') ans="No";
        else if(i==h-1&&0==j&&s.at(i-1).at(j)=='.'&&s.at(i).at(j+1)=='.') ans="No";
        else if(i==h-1&&j==w-1&&s.at(i-1).at(j)=='.'&&s.at(i).at(j-1)=='.') ans="No";
        if(ans=="No") break;
      }
      if(ans=="No") break;
    }
  }
  cout<<ans<<endl;
}