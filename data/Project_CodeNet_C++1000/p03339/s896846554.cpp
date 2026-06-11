#include <iostream>
#include <string>

#define MAXN 300000

using namespace std;

int A[MAXN];
int B[MAXN];

int main()
{
  string s;
  int sum = MAXN+1;
  int tmp;

  cin >> tmp;

  cin >> s;

  for ( int i = 0; i < s.size(); ++i ) {
    if ( s[i] == 'E' ) ++A[i];
    else ++B[i];
  }

  for ( int i = 1; i < s.size(); ++i ) {
    A[i] = A[i-1]+A[i];
    B[i] = B[i-1]+B[i];
  }

  sum = A[s.size()-1]-A[0];
  for ( int i = 1; i < s.size(); ++i ) {
    int tmp = B[i-1]+A[s.size()-1]-A[i];
    if ( tmp < sum ) sum = tmp;
  }

  cout << sum << endl;
}
