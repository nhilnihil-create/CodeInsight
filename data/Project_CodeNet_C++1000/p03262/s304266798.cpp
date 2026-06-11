#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b){
  if(a%b == 0){
    return b;
  }else{
    return gcd(b, a%b);
  }
}
int gcd_arr(vector<int> &a){
  int n = a.size();
  for(int i=n-2; i>=0; i--){
    a[i] = gcd(a[i], a[i+1]);
  }
  return a.front();
}

int main(void){
    long long int i=0,j,c=0,n,m=0,ans=0,z=0;
    string s;
    cin >> n >> m;
    vector<int> x(n);
    for(i=0;i<n;i++)
    {
        cin >> x[i];
        x[i]=abs(m-x[i]);
    }
    c=gcd_arr(x);
    cout << c << endl;
    return 0;
}
