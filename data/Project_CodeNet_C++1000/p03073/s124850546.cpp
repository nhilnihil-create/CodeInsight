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
  int N = S.length();
  int sum0=0;
  int sum1=0;
  for (int i=0;i<N;i++){
    if(i%2==0){
      if(S[i]=='0') ++sum0;
      else ++sum1;
    }else{
      if(S[i]=='0') ++sum1;
      else ++sum0;
    }
  }
  cout << N-max(sum0,sum1) << endl;
}
