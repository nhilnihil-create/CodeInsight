#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

int main(){

  ll a,b;
  cin >> a >> b;

  if((b-a)%4==0){
    if(a%2==0)cout << b <<endl;
    else cout << a << endl;
  }
  else if((b-a)%4==1){
    if(a%2==0)cout << 1 << endl;
    else{
      ll c=a^b;
      cout << c << endl;
    }
  }
  else if((b-a)%4==2){
    if(a%2==0){
      ll c=b^1;
      cout << c << endl;
    }
    else{
      ll c=a^1;
      cout << c << endl;
    }
  }
  else{
    if(a%2==0)cout << 0 << endl;
    else{
      ll c=a^1^b;
      cout << c << endl;
    }
  } 

}