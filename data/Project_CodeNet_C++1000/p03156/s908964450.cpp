#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,A,B;
  cin>>N;
  cin>>A>>B;
  int P[N];
  int p1=0,p2=0,p3=0;
  for(int i=0;i<N;i++){
    cin>>P[i];
    if(P[i]<=A){
      p1++;
    }
    else if(P[i]<=B){
      p2++;
    }
    else p3++;
  }
  cout<<min(min(p1,p2),p3)<<endl;
  return 0;
}

  
  