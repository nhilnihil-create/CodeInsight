#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};

 
int main(){
  char a;
  cin >> a;
  char ans;
  switch(a){
    case 'A':
      ans = 'T';
      break;
    case 'T':
      ans = 'A';
      break;
    case 'G':
      ans = 'C';
      break;
    case 'C':
      ans = 'G';
      break;
    default:
      break;
  }
  cout << ans << endl;
  return 0;
}
