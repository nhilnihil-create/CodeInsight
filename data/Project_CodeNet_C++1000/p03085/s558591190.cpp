#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <vector>
#define rep(i, s, n) for (int i = s; i < (n); i++)
#define ll long long int
using namespace std;

int main(void) {
  char b;
  cin >> b;
  
  if ( b == 'A' ) printf("T\n");
  else if ( b == 'T' ) printf("A\n");
  else if ( b == 'C' ) printf("G\n");
  else printf("C\n");
  
  return 0;
}
