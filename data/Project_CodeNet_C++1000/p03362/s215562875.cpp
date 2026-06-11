#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> Pii;
typedef pair<int, ll> Pil;
typedef pair<ll, ll> Pll;
typedef pair<ll, int> Pli;
typedef vector < vector<ll> > Mat;

#define fi first
#define se second

const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll MOD3 = 1812447359;
const ll INF = 1ll << 62;
const double PI = 2 * asin(1);

void yes() {printf("yes\n");}
void no() {printf("no\n");}
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

bool Judge_Prime(int num){
  if (num == 1) return false;
  for (int i = 2; i * i <= num; i++){
    if (num % i == 0) return false;
  }
  return true;
}

int N;
vector <int> Prime;

int main(){
  cin >> N;
  for (int i = 1; i <= 55555; i+=5){
    if (Judge_Prime(i)) Prime.push_back(i);
  }

  cout << Prime[0];
  for (int i = 1; i < N; i++) cout << " " << Prime[i];
  cout << endl;

  return 0;
}
