#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int find(int n)
{
  int sum = 0;
  while(n > 0){
    sum += n%10;
    n /= 10;
  }
  return sum;
}


int main() {
  int N,A,B;
  cin >> N >> A >> B;

  int total = 0;
  for(int i = 1; i <= N; i++){//20までの整数
    int sum = find(i);
    if(A <= sum && sum <= B){
      total += i;
    }
  }
  cout << total << endl;


}



