#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0;i<n;i++)
#define erep(i,n) for(int i = 0;i<=n;i++)
#define rep1(i,n) for(int i = 1;i<n;i++)
typedef long long ll;
#define vint vector<int>
#define vstring vector<string>
#define vll vector<ll>
#define vbool vector<bool>
#define INF 100000000

int main(){
  int64_t a,b;
  cin >> a >> b;
  if(b%2 == 0){
    cout << (int64_t)(pow(a/b,3)) + (int64_t)(pow((a+(b/2))/b,3)) << endl;
  }
  else{
    cout << (int64_t)(pow(a/b,3)) << endl;
  }
}

