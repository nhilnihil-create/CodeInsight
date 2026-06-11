#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
  
int main()
{
  int A, B, C;
  cin >> A >> B >> C;

  int a = A%2;
  int b = B%2;
  int c = C%2;
  if(a==b&&b==c){
    int MAX = max(max(A,B),C);
    cout << (MAX-A+MAX-B+MAX-C)/2 << endl;
  }else if(a==b){
    int MAX = max(max(A+1,B+1),C);
    cout << (MAX-A-1+MAX-B-1+MAX-C)/2+1 <<endl;
  }else if(c==b){
    int MAX = max(max(A,B+1),C+1);
    cout << (MAX-A+MAX-B-1+MAX-C-1)/2+1<< endl;
  }else if(a==c){
    int MAX = max(max(A+1,B),C+1);
    cout << (MAX-A-1+MAX-B+MAX-C-1)/2+1 << endl;
  }
}