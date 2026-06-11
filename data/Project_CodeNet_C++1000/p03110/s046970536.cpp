#include <bits/stdc++.h>
using namespace std;

int main(){
  
  long double n,ans=0;
  cin >> n;
  for(long long i=0; i<n; i++){
    long double x;
    string S;
    cin >> x >> S;
    if(S=="JPY"){
      ans+=x;
    }
    else{
      ans+=(x*380000);
    }
  }
  
  cout << fixed << setprecision(10) << ans << endl;
}

