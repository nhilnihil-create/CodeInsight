#include<bits/stdc++.h>
#include<cctype>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define all(v) (v).begin(),(v).end()
typedef long long int ll;
#define pi 3.1415926535897932384
#define E9 1000000000
#define eps 1e-4
#define pii pair<int,int>

int main(){
  int A, B, C, X; cin >> A >> B >> C >> X;

  int cnt = 0;
  for (int a=0;a<=A;a++){
    for (int b=0;b<=B;b++){
      int res = X-500*a-100*b;
      if (res%50==0 && 0<=res && res/50 <= C) cnt++; 
    }
  }

  cout << cnt << endl;



  // cout << fixed << setprecision(6);
  return 0;
}
