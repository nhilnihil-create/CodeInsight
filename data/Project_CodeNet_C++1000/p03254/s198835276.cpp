#include <bits/stdc++.h>
using namespace std;



int main()
{
  int N,x;
  cin >> N >> x;
  vector<int> a(N);
  for (int i = 0; i < N; i++)
  {
    cin >> a.at(i);
  }
  int count=0;
  sort(a.begin(), a.end());
  //reverse(a.begin(), a.end());
  for (int i = 0; i < N; i++)
  {
    if(a.at(i) <= x && i != N-1){
      x -= a.at(i);
      ++count;
    }
    else if (i == N - 1){
      if(x==a.at(i)){
        ++count;
      }
    }
  }
  cout << count << endl;
}
