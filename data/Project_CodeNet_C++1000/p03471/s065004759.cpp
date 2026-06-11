#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,Y;
  cin >> N >> Y;
  int total=0;
  bool check=false;
  int resa=-1,resb=-1,resc=-1;
  for(int a=0; a<=N;a++){
    for(int b=0; a+b<=N;b++){
      int c=N-a-b;
      total = 10000*a + 5000*b + 1000*c;
      if(total==Y){
        resa=a;
        resb=b;
        resc=c;
      }
    }
  }
  cout<<resa<<" "<<resb<<" "<<resc<<endl;
}
    
       