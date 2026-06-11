#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <climits>
#include <utility>
typedef long long ll;
using namespace std;

string buff;

void search(int l, char ls, int r, char rs){
  int mid = (l+r) / 2;
  cout << mid << endl;
  cin >> buff;
  if(buff[0]=='V'){
    return;
  }

  if((ls==buff[0]&&(mid-l)%2==1)||(ls!=buff[0]&&(mid-l)%2==0)){
    search(l,ls,mid,buff[0]);
  }
  else{
    search(mid,buff[0],r,rs);
  }

  return;
}

int main(void){
  int n;
  char ls, rs;
  cin >> n;

  cout << 0 << endl;
  cin >> buff;
  if(buff[0]=='V') return 0;
  else ls = buff[0];

  cout << n-1 << endl;
  cin >> buff;
  if(buff[0]=='V') return 0;
  else rs = buff[0];

  search(0,ls,n-1,rs);

  return 0;
}
