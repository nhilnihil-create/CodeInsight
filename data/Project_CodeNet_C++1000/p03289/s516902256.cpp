#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin>>S;
  int num=0;
  if(S[0]=='A'){
    num++;
  }
  int num_1=0;
  int size=S.size();
  for(int i=2;i<size-1;i++){
    if(S[i]=='C'){
      num_1++;
    }
  }
  if(num_1==1){
    num++;
  }
  int num_2=0;
  for(int i=0;i<size;i++){
    if(isupper(S[i])) num_2++;
  }
  if(num_2==2) num++;

  if(num==3) cout<<"AC"<<endl;
  else cout<<"WA"<<endl;

}
