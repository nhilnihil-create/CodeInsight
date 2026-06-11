#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#define printl(s) cout << s << endl;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
using vvi = vector<vector<int>>;

const ll modSeed = pow(10,9) + 7;
const int INF = 1'000'000'000;

template <typename T>
vector<T> getVector(ll num){
    vector<T> values(num);
    for(ll i=0;i<num;i++){
        cin >> values.at(i);
    }
    return values;
}

string S;
ll N,ans;

int main(){
  ans = 0;
  cin >> N;
  for(int c=0;c<=N;c++){
    for(int d=0;d<=N-c;d++){
      int p = 4*c+7*d;
      if(p==N){
        printl("Yes");
        return 0;
      }
    }
  }
  printl("No");
}
