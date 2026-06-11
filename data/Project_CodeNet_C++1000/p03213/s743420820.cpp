#include<bits/stdc++.h>
using namespace std;

int main(){
  vector<int> P={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
//素数は25個  
  vector<int> count(25, 0);
  int N;
  cin >> N;
  for(int i=0; i<25; i++){
    for(int j=1; j<=N; j++){
      int n=j;
      int p=P.at(i);
      while(n%p==0){
        n=n/p;
        count.at(i)++;
      }
    }
  }
  vector<int> C(75, 0);
  for(int i:{2, 4, 14, 24, 74}){
    for(int j=0; j<25; j++){
      if(count.at(j)>=i){
        C.at(i)++;
      }
    }
  }
  int Ans=0;
  Ans+=C.at(74);
  Ans+=C.at(24)*(C.at(2)-1);
  Ans+=C.at(14)*(C.at(4)-1);
  Ans+=(C.at(4)*(C.at(4)-1)/2)*(C.at(2)-2);
  cout << Ans << endl;
}
