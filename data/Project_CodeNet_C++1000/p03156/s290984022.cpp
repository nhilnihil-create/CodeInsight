#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main() {
  
  int N,A,B;
  cin >> N >> A >> B;

  vector<int> P(N);
  for(int i = 0;i < N;i++) {
    cin >> P.at(i);
  }

  sort(P.begin(),P.end());
  int o = 0,t = 0,th = 0;
  for(int i = 0;i < N;i++) {
    if(P.at(i) <= A) o++;
    else if(P.at(i) > A && P.at(i) <= B) t++;
    else th++;
  }

  cout << min(o,min(t,th)) << endl;

}

