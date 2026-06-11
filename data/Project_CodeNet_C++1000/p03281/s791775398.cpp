#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (ll i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define m1(x) memset(x,-1,sizeof(x))
const int INF = 1000000001;
const ll MOD = 1000000007;

int main(){
  int n;
  int table[300];
  fill(table, table+300,0);
  cin>>n;
  for(int i=1;i<300;i++){
    int k=1;
      while(k*i<300){
        table[k*i]++;
        k++;
      }
  }
  int cnt=0;
  for(int i=1; i<=n;i+=2)
    if(table[i]==8) cnt++;
    
  cout<<cnt<<endl;
}