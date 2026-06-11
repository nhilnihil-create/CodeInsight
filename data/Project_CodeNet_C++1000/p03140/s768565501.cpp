#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;

int main(){
  cout << setprecision(10);
  int N;
  cin >> N;
  string A,B,C;
  cin >> A >> B >> C;

  int ans = 0;
  for(int i = 0; i < N; i++){
    char a = A[i];
    char b = B[i];
    char c = C[i];

    if(a == b && b == c){ 
      continue;
    } else if(a == b || b == c || c == a){
      ans += 1;
    } else{
      ans += 2;
    }

  }
  cout << ans << endl;

}
