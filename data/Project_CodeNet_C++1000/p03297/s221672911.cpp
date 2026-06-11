#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vb = vector<bool>;
using vc = vector<char>;
using vs = vector<string>;
using vvi = vector<vector<int>>;
using vvc = vector<vector<char>>;
using pii = pair<int, int>;
#define fix10 cout << fixed << setprecision(10);
#define rep(i,n) for(int i=0; i<(int)(n);i++)
#define MOD 1000000007

long gcd(long a,long b){
  if(b == 0) return a;
  else return gcd(b,a%b);
}

int main(){
  int t;
  cin >> t;
  rep(i,t){
    long a,b,c,d;
    cin >> a >> b >> c >> d;
    long g = gcd(d,b);
    long r = a % b;
    if(a < b){
      cout << "No" << endl;
    }else if(d < b){
      cout << "No" << endl;
    }else if(b-1 <= c){
      cout << "Yes" << endl;
    }else if(g == 1){
      cout << "No" << endl;
    }else if(b - g + (r%g) > c){
      cout << "No" << endl;
    }else{
      cout << "Yes" << endl;
    }
  }
}