#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)

int main(){
 int a,b,k;
  cin >> a >> b>>k ;
  if(b-a+1>=2*k){
  rep(i,k){
    cout << a+i << endl;
  }
  rep(i,k){
    cout << b-k+1+i << endl;
  }
  }
  else{
    for(int i=a;i<=b;i++){
      cout << i << endl;
    }
  }     
}