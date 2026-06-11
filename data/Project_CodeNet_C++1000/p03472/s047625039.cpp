#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(int)n; i++)
#define rep2(i,a,n) for(int i=(a); i<(int)(n); i++)
#define all(vec) vec.begin(),vec.end()
using ll = long long;
using vi = vector<int>;
using vs = vector<string>;
using vvi = vector<vi>;
using vll = vector<ll>;
using pii = pair<int, int>;
using psi = pair<string, int>;
const int dx[4] = {1, 0,-1, 0};
const int dy[4] = {0, 1, 0,-1};
const ll mod = 1e9+7;
int gcd(int a, int b){if(a<b) swap(a,b); if (a%b == 0){return(b);}else{return(gcd(b, a%b));}}
int lcm(int a, int b){return a * b / gcd(a, b);}

long long N, M, K, H, W, L, R;

int main(){
  cin >> N >> H;
  int at1 = 0;
  vi at2(N);
  rep(i,N){
    int a; cin >> a;
    at1 = max(at1, a);
    cin >> at2[i];
  }
  sort(all(at2),greater<int>());
  int chkat = 1e9;
  rep(i,N){ 
    if(at2[i]<at1){chkat=i; break;}
  }
  int cnt = 0;
  rep(i,N){
    if(i==chkat){ 
      break;
    }
    H = H-at2[i];
    cnt++;
    if(H<=0) break;
  }
  
  if(H>0) cnt += (H+at1-1)/at1;
  cout << cnt << endl;
  return 0;
}