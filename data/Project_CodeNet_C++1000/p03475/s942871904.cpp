#include<bits/stdc++.h>
#define rep(i,f,n) for(int i=(f); (i) < (n); i++)
#define repe(i,f,n) for(int i=(f); (i) <= (n); i++)
using namespace std;

typedef long long ll;
ll INF = 1LL << 60;

int 
main() 
{

  int n; cin >> n;
  vector<vector<int>> arr(n - 1);
  rep(i, 0, n - 1){
    rep(j, 0, 3){
      int tmp; cin >> tmp;
      arr[i].push_back(tmp);
    }
  }

  rep(i, 0, n - 1){
  int acum = 0;
    for(int k =  i; k < n - 1; k++){
      if(acum <= arr[k][1]){
        acum += arr[k][0] + (arr[k][1] - acum);
      } else if ((acum - arr[k][1]) % arr[k][2] == 0){
        acum += arr[k][0];
      } else {
        acum += arr[k][0] +  arr[k][2] - (acum - arr[k][1]) % arr[k][2];
      }
    }
    cout << acum << endl;
  }

  cout << 0  << endl;

  return 0;
}


