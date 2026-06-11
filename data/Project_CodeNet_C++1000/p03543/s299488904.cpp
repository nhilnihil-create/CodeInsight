#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  if(((N%1000)/100) == ((N%100)/10)){
    if((((N%1000)/100) == (N/1000)) || (((N%1000)/100) == N%10)){
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  } else {
    cout << "No" << endl;
  }
  return 0;
}
