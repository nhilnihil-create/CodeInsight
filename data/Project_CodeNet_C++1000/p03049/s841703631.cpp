    #include <bits/stdc++.h>
    using namespace std;

    //long long
    using ll = long long;

    // pair<int, int>
    using PII = pair<int, int>;

    //最大値、mod
    const int MOD = 1000000007;
    const int INF = 1000000000;
    const long long LINF = 1e18;

    //出力系
    #define print(x) cout << x << endl
    #define prints(x) cout << fixed << setprecision(10) << x << endl
    #define printc(x) cout << setw(2) << setfill('0') << x << endl;
    #define yes cout << "Yes" << endl
    #define YES cout << "YES" << endl
    #define no cout << "No" << endl
    #define NO cout << "NO" << endl
    
    // begin() end()
    #define all(x) (x).begin(),(x).end()

    //for
    #define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)

    //最大公約数 
    unsigned gcd(unsigned a, unsigned b) {
      if(a < b) return gcd(b, a);
      unsigned r;
      while ((r=a%b)) {
        a = b;
        b = r;
      }
      return b;
    }

    // 最小公倍数
    unsigned lcm(unsigned a, unsigned b){
        return a / gcd(a, b) * b; 
    }

    // a = max(a, b), a = min(a, b)
    template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
    template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

    //int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};









int main(){
  int N;
  cin >> N;
  int a = 0;
  int b = 0;
  int ab = 0;
  int ans = 0;
  vector<string>S(N);
  REP(i, N){
    cin >> S.at(i);
    int len = S.at(i).length();
    if(S.at(i).at(0) == 'B' && S.at(i).at(len - 1) == 'A') ab++;
    else if(S.at(i).at(0) == 'B') b++;
    else if(S.at(i).at(len - 1) == 'A') a++;
    for(int j = 0; j < len - 1; j++){
      if(S.at(i).at(j) == 'A' && S.at(i).at(j + 1) == 'B') ans++;
    }
  }
if(a + b == 0) ans +=max(0, ab - 1); 
else ans += ab + min(a, b);
print(ans);

}