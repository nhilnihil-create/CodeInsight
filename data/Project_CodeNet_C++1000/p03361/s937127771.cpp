#include <bits/stdc++.h>
using namespace std;

int main(){
  int H,W;
  cin>>H>>W;
  vector<string> S(H);
  for(string &s:S)
    cin>>s;
  for(int i=0;i<H;i++)
    for(int j=0;j<W;j++){
      if(S[i][j]=='.')
        continue;
      else if(i!=0 && S[i-1][j]=='#')
        continue;
      else if(i!=H-1 && S[i+1][j]=='#')
        continue;
      else if(j!=0 && S[i][j-1]=='#')
        continue;
      else if(j!=W-1 && S[i][j+1]=='#')
        continue;
      else{
        cout<<"No"<<endl;
        return 0;
      }
    }
  cout<<"Yes"<<endl;
}