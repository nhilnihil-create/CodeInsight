#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
  int ans=0;
  string s;
  cin >> s;
  int a = (s[0]-'0')*10 + (s[1]-'0'), b = (s[2]-'0')*10+(s[3]-'0');
  if(a>=1&&a<=12) ans+=2;
  if(b>=1&&b<=12) ans+=1;
  
  if(ans==0){
    cout << "NA" << endl;
  } else if(ans==1){
    cout << "YYMM" << endl;
  } else if(ans==2){
    cout << "MMYY" << endl;
  } else {
    cout << "AMBIGUOUS" << endl;
  }
}