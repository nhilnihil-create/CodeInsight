#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,Q;
  cin>>N>>Q;
  string S;
  cin>>S;
  int len=S.length();
  int AC[len+1];
  AC[0]=0;
  int flag=0;
  int cnt=0;
  for(int i=0;i<len;i++){
    if(flag==1 && S.at(i)=='C'){
      cnt++;
    }
    if(S.at(i)=='A'){
      flag=1;
    }
    else{
      flag=0;
    }

    AC[i+1]=cnt;
  }
  //cout<<AC[0]<<" "<<AC[1]<<" "<<AC[2]<<" "<<AC[3]<<endl;
  int l,r;
  for(int i=0;i<Q;i++){
    cin>>l>>r;
    cout<<AC[r]-AC[l]<<endl;
  }
  return 0;
}
