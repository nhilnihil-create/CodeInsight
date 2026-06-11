#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};
 
int main(){
  int n;
  cin >> n;
  string ans = "No";
  for(int i=0; i<n/4+1; i++){
    int tmp = n - 4*i;
    if(tmp%7==0) ans = "Yes";
  }
  cout << ans << endl;
  return 0;
}
