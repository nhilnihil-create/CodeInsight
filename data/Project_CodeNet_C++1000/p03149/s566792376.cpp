// B

#include <bits/stdc++.h>
using ll = long long;
using namespace std;
ll mod=1e9+7;
#define pa(x,n) for(ll i=0;i<n;i++){cout<<(x[i])<<" \n"[i==n-1];};

int main(){
  int N[4];
  for (int i(0);i<4;i++) cin>>N[i];
  sort(N,N+4);
  if (N[0] == 1 && N[1] == 4 && N[2] == 7 && N[3] == 9){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
}


