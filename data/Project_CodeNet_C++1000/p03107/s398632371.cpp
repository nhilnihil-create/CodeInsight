#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
typedef long long ll;

int main(){
  string S;
  cin >> S;
  int N = S.size();
  int a=0;
  int b=0;
  for(int i=0;i<N;i++){
    if(S[i]=='1') a++;
    else b++;
  }
  if(a>b) cout << 2*b << endl;
  else cout << 2*a << endl;
}
