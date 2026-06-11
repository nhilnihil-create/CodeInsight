#include<bits/stdc++.h>
#define INF 1000000000000000000
using namespace std;

int main(){
  long long A,B,C,K,a,b,c;
  cin >> A >> B >> C >> K;
  if(K%2==0){
    cout << A-B << endl;
  }else{
    cout << B-A << endl;
  }
  return 0;
}
