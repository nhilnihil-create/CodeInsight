#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> P;
 
#define mod 1000000007
#define inf 1000000000
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define popcount(x) __builtin_popcountll(x)
 
const long double PI = acos(-1);
 
ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a / gcd(a,b) * b;}
ll stringcount(string s, char c){return count(s.cbegin(), s.cend(), c);}
bool isInteger(double x){return floor(x) == x;}

int main(){
  double N;
  cin >> N;

  for(double h = 1; h <= 3500; h++){
    for(double n = 1; n <= 3500; n++){
      double w = (N*n*h) / (4*h*n-N*n-N*h);
      if(w > 0 && w <= 3500 && isInteger(w)){
        cout << (int)h << " " << (int)n << " " << (int)w << endl;
        return 0;
      }
    }
  }
  return 0;
}