#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
string vac = "Vacant";

bool chk(string sl, string sr, int left, int right)
{
  if(sl==sr) return (right-left)%2==1;
  else return (right-left)%2==0;
}

int main()
{
  int n; cin >> n;
  int left = 0, right = n/2;
  string sl, sr, str;
  cout << left << endl;
  cin >> sl;
  if(sl==vac) return 0;
  cout << right << endl;
  cin >> sr;
  if(sr==vac) return 0;
  
  if(!chk(sl,sr,left,right)){
    swap(sl,sr);
    left = right;
    right = n;
  }
  
  while((right-left)>1){
    int mid = (right+left)/2;
    cout << mid << endl;
    cin >> str;
    if(str==vac) return 0;
    if(chk(sl,str,left,mid)){
      sr = str;
      right = mid;
    }else{
      sl = str;
      left = mid;
    }
  }

  return 0;
}
