#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  string S;
  int A;
  cin>>N;

  for (int i = 0; i < N; i++)
  {
    cin>>S;
    if (S=="Y")
    {
      A++;
    }
  }

  if (A>=1)
  {
    cout<<"Four";
  }

  else
  {
    cout<<"Three";
  }
}