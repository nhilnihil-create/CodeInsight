#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  ll k,a,b;
  cin >> k >> a >> b;
  if(a+2>=b||k<=a){
    cout << k+1 << endl;
    return 0;
  }
  
  cout << a+(k-a+1)/2*(b-a)+(k-a+1)%2 << endl;
}