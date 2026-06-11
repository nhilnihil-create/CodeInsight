#include<bits/stdc++.h>
using namespace std;
#define rep(i,s, n) for(int i = s; i < (int)(n); i++)
#define co(x) cout<<x<<endl
#define SQvec(i,j) vector<vector<int>> data(i, vector<int>(j))
#define mod 1000000000+7
typedef long long int lint;

int main() {
  int N,M,max,min,cnt = 0;
  cin >> N >> M;
  vector<int> a(M),b(M);
  rep(i,0,M){
    cin >> a[i] >> b[i];
  }
  
  max = *max_element(a.begin(),a.end());
  min = *min_element(b.begin(),b.end());
  
  while(max >= min){
    rep(i,0,a.size()){
      if(a[i] < min){
        a[i] = 1;
        b[i] = N;
      }
    }
    cnt++;
    max = *max_element(a.begin(),a.end());
    min = *min_element(b.begin(),b.end());
  }
  co(cnt + 1);
}