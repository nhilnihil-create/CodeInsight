#include <bits/stdc++.h> //C++の標準ライブラリを一行で一括でインクルードする
#include <math.h> //数学関数と数学定数を利用する
#define rep(i,n) for (int i = 0; i < (n); i++)
#define PI 3.141592653589793
using namespace std;
typedef long long ll;
template<class T> void chmax(T &a,T b) { if (a<b) a=b;}
template<class T> void chmin(T &a,T b) { if (a>b) a=b;}
int gcd(int a, int b){//ユークリッドの互除法
  if (a < b) gcd(b,a); //aの方がbよりでかいのが前提
  if (b == 0) return a; //aをbで割り切れたらreturn
  else gcd(b, a % b);
}
const int INF = 1<<30;
const int MOD = 1000000007;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

int n,q;
string s;
vector<pair<char,int>> query;

bool checkL(int pos){
  char now_c = s[pos];
  rep(i,q){
   if(query[i].first == now_c){
     pos += query[i].second;
     now_c = s[pos];
     if(pos == 0) return true; //一番左まで行ったらtrue
   }
  }
  return false; //一番左まで行けなかったらfalse
}
bool checkR(int pos){
  char now_c = s[pos];
  rep(i,q){
   if(query[i].first == now_c){
     pos += query[i].second;
     now_c = s[pos];
     if(pos == n+1) return true; //一番右まで行ったらtrue
   }
  }
  return false; //一番右まで行けなかったらfalse
}

int main(){
  cin >> n >> q >> s;
  s = 'a' + s + 'a';
  rep(i,q){
    char t,d; cin >> t >> d;
    int move;
    if(d=='L') move = -1;
    else move = 1;
    query.push_back({t,move});    
  }
  
  int l = 0, r = n+1;
  while(r-l>1){
    int c = (l+r)/2;
    if(!checkL(c)) r = c;
    else l = c;
  }
  int left_lim = l;
  l = 0, r = n+1;
  while(r-l>1){
    int c = (l+r)/2;
    if(checkR(c)) r = c;
    else l = c;
  }
  int right_lim = r;
  //printf("left=%d right=%d\n",left_lim,right_lim);
  
  cout << n- (left_lim + 1) - (n - right_lim) << endl;
  return 0;
}