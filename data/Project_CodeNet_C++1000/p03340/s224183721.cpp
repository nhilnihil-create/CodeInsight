#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define rep2(i, s, n) for(int i=s; i<(n); ++i)
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;

static const int INTINF = (2147483647);
static const ll LLINF = (9223372036854775807);
static const int MAX = 1e5+1;
static const ll MOD = 1e9+7;

namespace Printer{
    template<class T>
    void print(T x){
        cout << x << endl;
    }

    template<class T>
    void print(vector<T> v){
        rep(i, v.size()){
            if(i) cout << " ";
            cout<< v[i];
        }
        cout << endl;
    }

    template<class T>
    void print(vector<vector<T> > vv){
        rep(i, vv.size()){
            rep(j, vv[i].size()){
                if(j) cout << " ";
                cout << vv[i][j];
            }
            cout << endl;
        }
    }

    void print(pair<int, int> p){
        cout << "(" << p.first << ", " << p.second << ")" << endl;
    }
};
using namespace Printer;

//--global--//



//----------//

int main(){
  int N; cin >> N; int a[N];
  rep(i, N){
    cin >> a[i];
  }
  int left = 0, right = 0, bits=0; ll ans = 0;
  rep(left, N){
    while(right<N && (bits^a[right])==(bits+a[right])){
      bits^=a[right]; right++;
    }
    ans+=right-left;
    if(right==left) right++;
    else bits^=a[left];
  }
  cout << ans << endl;
}