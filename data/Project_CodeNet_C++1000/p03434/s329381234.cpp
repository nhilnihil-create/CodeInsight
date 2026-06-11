#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#define printl(s) cout << s << endl;
using ll = long long;
using pii = pair<int, int>;
using si = set<int>;

const ll modSeed = pow(10,9) + 7;
const int INF = 100'000'000;

template <typename T>
vector<T> getValues(ll num){
    vector<T> values(num);
    for(ll i=0;i<num;i++){
        cin >> values.at(i);
    }
    return values;
}

string S;
int N,ans;

int main(){
  cin >> N;
  int aSet[N];  
  int alice=0;
  int bob = 0;

  for(int i=0;i<N;i++){
    cin >> aSet[i];
  }

  sort(aSet,aSet+N,greater<int>());
  for(int i=0;i<N;i++){
    if(i%2==0){
      alice+=aSet[i];
    }else{
      bob+=aSet[i];
    }
  }
  ans = alice -bob;
  printl(ans);
}
