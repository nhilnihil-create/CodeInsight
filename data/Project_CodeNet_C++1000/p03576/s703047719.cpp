#include <bits/stdc++.h>
#define fi first
#define se second
#define m_p make_pair
#define p_b push_back
#define e_b emplace_back
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
using namespace std;
using ll = long long;
using ld = long double;
template<class T> bool chmax(T &a,T b){if(a<b){a=b;return true;}return false;}
template<class T> bool chmin(T &a,T b){if(a>b){a=b;return true;}return false;}

int main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  int N,K;
  cin >> N >> K;
  vector<pair<int,int>> xy(N);
  for(int i=0;i<N;i++){
    int x,y;
    cin >> x >> y;
    xy.at(i)=m_p(x,y);
  }

  vector<ll> px(N);
  vector<ll> py(N);
  for(int i=0;i<N;i++){
    px.at(i)=xy.at(i).fi;
    py.at(i)=xy.at(i).se;
  }
  sort(all(px));
  sort(all(py));

  ll ans=6e18;
  for(int px_i=0;px_i<N;px_i++){
    for(int px_j=px_i;px_j<N;px_j++){
      for(int py_i=0;py_i<N;py_i++){
        for(int py_j=py_i;py_j<N;py_j++){
          int cnt=0;
          ll lx=px.at(px_i);
          ll rx=px.at(px_j);
          ll ly=py.at(py_i);
          ll ry=py.at(py_j);
          for(int i=0;i<N;i++){
            int x=xy.at(i).fi;
            int y=xy.at(i).se;
            if(lx<=x && x<=rx && ly<=y && y<=ry) cnt++;
          }
          if(cnt>=K)  chmin(ans,(rx-lx)*(ry-ly));
        }
      }
    }
  }
  cout << ans << endl;

  return 0;
}