#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
#include<iomanip>
#define pi 3.14159265358979323846
#define ill long long int
#define rep(i, a, n) for(int i = a; i < n; i++)
using namespace std;
int main(){
  ill n, a;
  cin >> n >> a;
  if(n >= 500){
    n = n % 500;
    if(n <= a){
      cout << "Yes\n";
      return 0;
    }
    cout << "No\n";
    return 0;
  }
  if(n <= a){
    cout << "Yes\n";
    return 0;
  }
  cout << "No\n";
  return 0;
}
  