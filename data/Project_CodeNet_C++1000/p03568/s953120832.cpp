#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,buf;
  cin >> N;

  int all= 1;
  int ng= 1;
  for(int i=0; i<N; i++){
    cin >> buf;
    all*= 3;

    if(buf%2==0){ ng*= 2; }
    else        { ng*= 1; }
  }

  int ans= all- ng;

  cout << ans << endl;
}