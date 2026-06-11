#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#define rep(i,n) for(int i=0;i<n;i++)
const long long MOD = 1000000007;
const long long INF = MOD*MOD;
typedef pair<int,int> P;
typedef long long ll;
ll n,m,k,ans;
string s;

int main(){
  int n,a,b;cin >> n >> a >> b;
  if((a-b)%2){
    cout << "Borys\n";
  }else{
    cout << "Alice\n";
  }
}