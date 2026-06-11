#include <bits/stdc++.h>
using namespace std;
 
int dis(int n){
    int sum=0;
    while(n>0){
      sum+=n%10;
      n/=10;
    }
    return sum;
  }

int main() {
  int N;
  cin>>N;
  
  
  
  int ini=dis(1)+dis(N-1);
  for(int i=2;i<(N+1)/2;i++){
    if(ini>(dis(i)+dis(N-i))){
      ini=dis(i)+dis(N-i);
    }
  }
  cout<<ini<<endl;
}
    