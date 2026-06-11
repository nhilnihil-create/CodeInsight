#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,M;
  cin >> N >> M;
  int64_t X=(N-M)*100+M*1900;
  X*=pow(2,M);
  cout << X << endl;
  return 0;
}
