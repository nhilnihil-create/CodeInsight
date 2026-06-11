#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int n;
  cin >> n;
  for(int i = 0;;i++){
    if(n%111==0){
      cout << n << endl;
      return 0;
    }
    n++;
  }
}