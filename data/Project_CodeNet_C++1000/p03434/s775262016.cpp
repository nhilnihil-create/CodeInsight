#include <bits/stdc++.h>
using namespace std;

#define printl(s) cout << s << endl;
#define print(s) cout << s << endl; return 0;
#define printFix(n,i) cout << fixed << setprecision(i) << n << endl; return 0;
#define yes cout << "Yes" << endl; return 0;
#define no cout << "No" << endl; return 0;
#define pass cout << "PASS" << endl;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep2(i,n) for (int i = 1; i < (n)+1; ++i)
#define bitrep(i,n) for (int i = 0; i < (1<<(n));i++)
#define isOne(bit,i) (bit & (1 << i))
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
  priority_queue<int,vector<int>,less<int>> que;
  int alice=0;
  int bob = 0;

  for(int i=0;i<N;i++){
    int a;
    cin >> a;
    que.push(a);
  }
  for(int i=0;i<N;i++){
    if(i%2==0){
      alice+=que.top();
    }else{
      bob+=que.top();
    }
    que.pop();
  }
  ans = alice - bob;
  printl(ans);
}
