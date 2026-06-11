#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0;i<n;i++)
#define erep(i,n) for(int i = 0;i<=n;i++)
#define rep1(i,n) for(int i = 1;i<n;i++)
#define erep1(i,n) for(int i = 1;i<=n;i++)
typedef long long ll;
#define vint vector<int>
#define vstring vector<string>
#define vll vector<ll>
#define vbool vector<bool>
#define INF 100000000

int main(){
  int n;
  cin >> n;
  vint A(n+2);
  int max = 0;
  A[0] = 0;
  A[n+1] = 0;
  erep1(i,n+1){
    cin >> A[i];
    max += abs(A[i]-A[i-1]);
  }
  erep1(i,n){
    cout << max + abs(A[i-1]-A[i+1]) - abs(A[i-1] - A[i]) - abs(A[i+1]-A[i]) <<endl;
  }
}