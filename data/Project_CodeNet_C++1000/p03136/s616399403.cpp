#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<iomanip>
#define pi 3.14159265358979323846
#define ll long long
#define rep(i, a, n) for(int i = a; i < n; i++)
using namespace std;
int main(){
  int n;
  cin >> n;
  int l[n];
  rep(i, 0, n){
    cin >> l[i];
  }
  sort(l, l + n);
  int sm = 0;
  rep(i, 0, n - 1){
    sm += l[i];
  }
  if(sm > l[n - 1]){
    cout << "Yes\n";
    return 0;
  }
  cout << "No\n";
}