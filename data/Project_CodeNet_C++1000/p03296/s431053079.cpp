#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main() {

  int N;
  cin >> N;

  vector<int> a(N);
  for(int i = 0;i < N;i++) {
    cin >> a.at(i);
  }

  a.push_back(10000);

  int sum = 0,num = 1;
  for(int i = 0;i < N;i++) {
    if(a.at(i) == a.at(i+1)) num++;
    else {
      sum += num / 2;
      num = 1;
    }
  }

  cout << sum << endl;
}