#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};

 
int main(){
  ll a, b;
  cin >> a >> b;
  ll anum, bnum;
  if(a==0){
    switch(b%4){
      case 0:
        bnum = b;
        break;
      case 1:
        bnum = 1;
        break;
      case 2:
        bnum = 1^b;
        break;
      case 3:
        bnum = 0;
        break;
      default:
        break;
    }
    cout << bnum << endl;
    return 0;
  }
  switch((a-1)%4){
    case 0:
      anum = a-1;
      break;
    case 1:
      anum = 1;
      break;
    case 2:
      anum = 1^a-1;
      break;
    case 3:
      anum = 0;
      break;
    default:
      break;
  }
  switch(b%4){
    case 0:
      bnum = b;
      break;
    case 1:
      bnum = 1;
      break;
    case 2:
      bnum = 1^b;
      break;
    case 3:
      bnum = 0;
      break;
    default:
      break;
  }
  ll ans = anum^bnum;
  cout << ans << endl;
  return 0;
}
