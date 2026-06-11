#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define mod 1000000007
using ll = long long;
using namespace std;
int main(){
  int n;
  cin >> n;
  if(n % 3 == 0){
    cout << n / 3 << endl;
  }else{
    n /= 3;
    cout << max(n, 0) << endl;
  }
}