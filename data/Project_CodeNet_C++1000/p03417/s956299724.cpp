#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int main(){
  ll n,m;
  cin >> n >> m;
  if(n==2 || m==2){
    cout << 0 << endl;
  }
  else if(n==1 && m==1){
    cout << 1 << endl;
  }
  else if(n==1){
    cout << max((ll)0,m-2) << endl;
  }
  else if(m==1){
    cout << max((ll)0,n-2) << endl;
  }
  else{
    cout << (m-2)*(n-2) << endl;
  }
}