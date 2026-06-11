#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;cin>>N;
  int ans=0;
  int count1=0,count2=0;
  int kaage=1;
  for(int i=0;i<N;i++){
    string S;cin>>S;
    bool a=false,b=false;
    if(S.at(0)=='B'){a=true;count1++;}
    if(S.at(S.size()-1)=='A'){b=true;count2++;}
    if(!a&&!b)kaage++;
    for(int j=0;j<S.size()-1;j++){
      if(S.at(j)=='A'&&S.at(j+1)=='B')ans++;
    }
  }
  cout<<ans+min(min(count1,count2),max(0,N-kaage))<<endl;
}
