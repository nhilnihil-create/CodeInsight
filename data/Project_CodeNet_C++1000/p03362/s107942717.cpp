#include <bits/stdc++.h>
#define rep(i,n)for(long long i=0;i<(n);i++)
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
const ll INF = (1LL << 31) - 1;
const double pi=acos(-1);
const int MAX = 10001000;
bool IsPrime[MAX];
vector<int> Era(int n = MAX) {
    vector<int> res;
    IsPrime[0] = false; IsPrime[1] = false; 
    for (int i = 2; i < n; ++i) IsPrime[i] = true;
    for (int i = 2; i < n; ++i) {
        if (IsPrime[i]) {
            res.push_back(i);
            for (int j = i*2; j < n; j += i) IsPrime[j] = false;
        }
    }
    return res;
}
int main(){
  Era();
  int n;
  cin >> n;
  int cnt=0;
  int num=16;
  cout << 11;
  while(cnt<n-1){
    if(IsPrime[num]){
      cout<<" "<<num;
      num+=5;
      cnt+=1;
    }
    else num+=5;
  }  
  cout << endl;
  return 0;
}
