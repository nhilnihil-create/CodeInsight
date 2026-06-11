#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  int N;
  cin >>N;
  vector<ll> a(N);
  vector<ll> c(N);
  for(int i=0;i<N;i++){
    cin >> a[i];
    c[i]=a[i];
  }
  sort(a.begin(),a.end());
  for(int i=0;i<N;i++){
    if(c[i]<a[(N/2)]){
     cout << a[(N/2)] <<endl;
    }
    else{
      cout << a[(N/2)-1] <<endl;
    }
  }
}

  
