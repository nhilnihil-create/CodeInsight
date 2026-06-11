#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define REP(i, a, n) for(int i=a; i<n; ++i)
#define pb push_back
#define sz(x) (int)((x).size())
#define all(x) (x).begin(), (x).end()

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const double PI = 3.141592653589793238460;
const ll mod = 1e9 + 7;

void FAST(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

int main(){
  FAST();

 int a, b, k;
 cin >> a >> b >> k;

 for(int i = min(a, b); i >= 1; --i){
     if((a % i == 0) && (b % i == 0))
        k--;
     if(k == 0){
        cout << i << endl;
        return 0;
     }
 }



  return 0;
}
