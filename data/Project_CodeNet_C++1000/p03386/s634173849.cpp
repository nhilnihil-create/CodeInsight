#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  int A , B , K;
  cin >> A >> B >> K;

  set<int> s;
  for (int i = A; i <= A + K - 1; i++){
    if (i >= A && i <= B){
      cout << i << endl;
      s.insert(i);
    }
    
  }

  for (int i = B - K + 1; i <= B; i++)
  {
    if (!s.count(i) && i >= A && i <= B){
      cout << i << endl;
    }
    
  }
  


}