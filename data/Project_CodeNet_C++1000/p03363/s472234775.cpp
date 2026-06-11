#include<bits/stdc++.h>
using namespace std;

int main(){
  int64_t N;
  cin >> N;
  vector<int64_t> Sum(N+1);
  Sum.at(0)=0;
  int64_t S=0;
  int64_t A;
  for(int64_t i=0; i<N; i++){
    cin >> A;
    S+=A;
    Sum.at(i+1)=S;
  }
  int64_t Ans=0;
  int64_t count=1;
  sort(Sum.begin(), Sum.end());
  for(int64_t i=1; i<N+1; i++){
    if(Sum.at(i)==Sum.at(i-1)){
      count++;
    }
    else if(Sum.at(i)!=Sum.at(i-1)){
      Ans+=count*(count-1)/2;
      count=1;
    }
  }
  Ans+=count*(count-1)/2;
  cout << Ans << endl;
}