#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

#define rep(i,n)for(int i=0; i<(int)(n); i++)
#define bitrep(tmp, N)for (int tmp=0; tmp < (1<<N);tmp++)
#define all(v) v.begin(), end.bigin()
//int INF = 10e9;
using P = pair<int,int>;


int main(){
  int N;
  cin >>N;
  vector<P> red(N);
  rep(i, N){
    int a, b;
    cin >> a >> b;
    red[i] = make_pair(a,b);
  }
  sort(red.begin(), red.end());
  vector<P> blue(N);
  rep(i, N){
    int c, d;
    cin >> c >> d;
    blue[i] = make_pair(c,d);
  }
  sort(blue.begin(), blue.end());
  int cnt = 0;
  vector<int> removed;
  rep(i,N){
    int m=-1;
    int pos=-1;
    rep(j,N){
      if(red[j].first<=blue[i].first && red[j].second<=blue[i].second && (!count(removed.begin(),removed.end(), j))){
        if(m<red[j].second){
          m = red[j].second;
          pos = j;
        }
      }
    }
    if(pos!=-1){
      cnt++;
      removed.push_back(pos);
    }
  }
  cout << cnt <<endl;
}