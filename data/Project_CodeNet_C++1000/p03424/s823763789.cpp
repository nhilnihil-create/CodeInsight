#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,i,count=0;
  char M;
  cin >> N;
  for (i=0 ; i < N ;i++){
    cin >> M;
    if (M == 'Y')count++;
}
    if(count >=1) cout << "Four" << endl;
     else cout << "Three" << endl;
}
