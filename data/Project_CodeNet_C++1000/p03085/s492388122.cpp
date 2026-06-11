#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main(void){
  char b; cin >> b;
  if(b == 'A') cout << "T" << endl;
  else if(b == 'T') cout << "A" << endl;
  else if(b == 'G') cout << "C" << endl;
  else cout << "G" << endl;
  return 0;
}
