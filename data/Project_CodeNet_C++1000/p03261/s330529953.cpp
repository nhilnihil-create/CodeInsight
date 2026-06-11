#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
typedef long long ll;

int main(){
  int N;
  cin >> N;
  string W[N];
  for(int i=0;i<N;i++){
    cin >> W[i];
  }
  bool item = true;
  for(int j=0;j<N-1;j++){
    if(W[j][W[j].size()-1]!=W[j+1][0]) item=false;
    for(int i=j+1;i<N;i++){
      if(W[j]==W[i]) item=false;
    }
  }
  if(item) cout << "Yes" <<endl;
  else cout << "No" << endl;
}
