#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
using P = pair<int,int>;

int main()
{
  int N;
  cin >> N;
  int left = 0;
  int right = N-1;
  cout << left << endl;
  string s1;
  cin >> s1;
  if(s1=="Vacant"){
    return 0;
  }
  cout << right << endl;
  string s2;
  cin >> s2;
  if(s2=="Vacant"){
    return 0;
  }
  REP(i,20){
    cout << (right+left)/2 << endl;
    string x;
    cin >> x;
    if(x=="Vacant"){
      return 0;
    }

    if((s1==x&&((right+left)/2-left-1)%2==1)||(s1!=x&&((right+left)/2-left-1)%2==0)){
      left=(right+left)/2;
      s1=x;
    }else{
      right=(right+left)/2;
    }
  }
}