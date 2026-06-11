#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<int,int>;

int main(void){
    int a, b, c, d;
  cin >> a >> b >> c >> d;
  if((abs(a-b) <= d && abs(b-c) <= d) || abs(a-c) <= d) cout << "Yes" << endl;
  else cout << "No" << endl;
    return 0;
}
