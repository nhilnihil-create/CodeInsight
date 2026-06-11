#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N = 0;
  cin >> N;
  vector<char> moji{'M', 'A', 'R', 'C', 'H'};
  vector<int> moji_count(5, 0);

  for(int i=0; i<N; i++) {
    string name;
    cin >> name;
    for(int j=0; j<5; j++) {
      if(name.at(0) == moji.at(j)) moji_count.at(j)++;
    }
  }

  long solution = 0;

  for(int i=0; i<3; i++) {
    for(int j=i+1; j<4; j++) {
      for(int k=j+1; k<5; k++) {
        long a = moji_count.at(i);
        long b = moji_count.at(j);
        long c = moji_count.at(k);
        solution += a*b*c;
      }
    }
  }

  cout << solution << endl;
  return 0;
}
