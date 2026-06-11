#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};

 
int main(){
  char a[3];
  cin >> a;
  for(int i=0; i<3; i++){
    if(a[i]=='1') cout << 9;
    else cout << 1;
  }
  cout << endl;
  return 0;
}
