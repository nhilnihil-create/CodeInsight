#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define intput(i) cout << i << endl
#define ll long long
#define stringput(s) cout << (string)(s) << endl

int main(){
  int a, b;
  cin >> a >> b;
  int sum = a+b;
  int dif = a-b;
  int pro = a*b;
  int m = max(max(sum,dif),pro);
  cout << m << endl;
}
