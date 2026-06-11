#include <bits/stdc++.h>
using namespace std;

int dpw(int a){
  int b=1;
  while(a){
    b*=2; a--;
  }
  return b;
}

int main(){
  int L; cin>>L;
  vector<int> V(19,0);
  int mx;
  for(int i=0;1;i++){
    V[i]=L%2;
    L/=2;
    if(L==0){
      mx=i;
      break;
    }
  }
  vector<vector<int>> ANS;
  for(int i=0;i<mx;i++){
    ANS.push_back({i+1,i+2,0});
    ANS.push_back({i+1,i+2,dpw(i)});
  }
  int a=0;
  for(int i=mx;i>=0;i--){
    if(V[i]){
      if(i!=mx)
        ANS.push_back({i+1,mx+1,a});
      a+=dpw(i);
    }
  }
  a=ANS.size();
  cout<<mx+1<<" "<<a<<endl;
  for(int i=0;i<a;i++)
    cout<<ANS[i][0]<<" "<<ANS[i][1]<<" "<<ANS[i][2]<<endl;
}