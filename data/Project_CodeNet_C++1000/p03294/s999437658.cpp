#include<iostream>
#include<cstdio>

typedef long long ll;

using namespace std;

int main()
{
  ll sum = 0;
  int n;

  cin >> n;

  for ( int i = 0; i < n; ++i ) {
    int tmp;
    scanf("%d", &tmp);
    sum += tmp;
  }

  sum -= n;

  cout << sum << "\n";
}
