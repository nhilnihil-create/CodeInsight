#include<bits/stdc++.h>
using namespace std;

int main(){
  int h,w;
  cin>>h>>w;
  char s[52][52];
  for(int i=1;i<=h;i++){
    for(int j=1;j<=w;j++){
      cin>>s[i][j];
    }
  }
  int count=0;
  for(int i=1;i<=h;i++){
    for(int j=1;j<=w;j++){
      if(s[i][j]=='#'&&s[i][j-1]!='#'&&s[i-1][j]!='#'&&s[i][j+1]!='#'&&s[i+1][j]!='#'){
        count++;
      }
    }
  }
  if(count==0){
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
}
        