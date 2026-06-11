#include <bits/stdc++.h>
using namespace std;

int main() {
int N,D,X;
cin >> N >> D>>X;
int sum=0;
vector<int> A(N);
for (int i = 0; i < N; i++)
{
 cin>>A[i]; 
}

for (int i = 0; i < N; i++)
{
  int date=0;
  for (int j = 0; j < 101; j++)
  {
    date=j*A[i]+1;
    if(date>D) break;
    sum++;
  }
}
cout << X+sum << endl;

  return 0;
}