#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int gcd(int a, int b){
  if(a%b==0)return b;
  else{
    return gcd(b,a%b);
  }
}
void solve3(){
  int n;
  cin >> n;
  vector <int> a(n);
  int res;
  int tmp;
  for(int i=0;i<n;i++){
    cin >> a[i];
    if(i>0){
      tmp = (gcd(a[i],tmp));
    }
    if(i==0){
      tmp = a[i];
    }
  }
  sort(a.begin(),a.end());
  int k=0;
  cout << tmp << endl;


}
int main(){
  solve3();
  return 0;
}
