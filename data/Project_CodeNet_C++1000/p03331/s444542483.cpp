#include <bits/stdc++.h>
using namespace std;

int div_sum(int n) {
  int sum = 0;
  while ( n > 0) {
    sum += n % 10;
    n /= 10; 
  }
  return sum;
}


int main () {
int n;
cin >> n ;

  int ans;
  int min_ans = 50;

  for (int i = 1 ; i <= n/2 ; i++) {
    ans = div_sum(i) + div_sum(n - i);
    min_ans = min(min_ans, ans);
  }

  cout << min_ans << endl;

}