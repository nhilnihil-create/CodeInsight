#include <bits/stdc++.h>
 using namespace std;

int main(){
  int N; cin >>N;
  vector<int> card(N);
   for(int i=0;i<N;i++){
    cin >> card[i];
   }
  sort(card.begin(),card.end());
  reverse(card.begin(),card.end());
  int Alice=0; int Bob=0;
  for(int i=0;i<N;i=i+2){
    Alice=Alice+card[i];
  }
  for(int j=1;j<N;j=j+2){
    Bob=Bob+card[j];
  }
  cout <<Alice-Bob<<endl;
}