#include <bits/stdc++.h>
using namespace std;

//repetition
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

//container util
#define all(x) (x).begin(),(x).end()

//typedef
typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VLL;
typedef vector<VLL> VVLL;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;


//conversion
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}
string s;
vector< pair<char,char> > query;
int n,q;

bool checkRight(int x){
  int current = x;

  rep(i,q){
    if(s[current] == query[i].first){
      if(query[i].second == 'L'){
        current--;
        if(current < 0) return false;
      }else{
        current++;
        if(current == n) return true;
      }
    }
  }
  return false;
}

bool checkLeft(int x){
  int current = x;

  rep(i,q){
    if(s[current] == query[i].first){
      if(query[i].second == 'L'){
        current--;
        if(current < 0) return true;
      }else{
        current++;
        if(current == n) return false;
      }
    }
  }

  return false;
}

int main(){
  cin >> n >> q;
  cin >> s;
  rep(i,q){
    char x,y;
    cin >> x >> y;
    query.push_back(make_pair(x,y));
  }

  //binary serch
  //right edge
  int right = n - 1,left = 0;
  int rightEdge = 0, leftEdge = 0;
  if( checkRight(right) == false){
    rightEdge = n-1;
  }else{
    while(right - left > 1){
      int mid = (right + left)/2;
      bool flag = checkRight(mid);

      if(flag == true){right = mid;}
      if(flag == false){left = mid;}
      if(left == right){
        break;
      }
    }
    rightEdge = right-1;
  }
  //cout << "rightEdge " <<  rightEdge << endl;

  //left edge
  right = n-1,left = 0;
  if( checkLeft(left) == false){
    leftEdge = 0;
  }else{
    while(right - left > 1){
      int mid = (right + left)/2;
      bool flag = checkLeft(mid);
      if(flag == true){left = mid;}
      if(flag == false){right = mid;}
      if(left == right){
        break;
      }
    }
    leftEdge = left+1;
  }
  //cout << "leftEdge " <<  leftEdge << endl;
  if(rightEdge <= 0){
    cout << 0 << endl;
    return 0;
  }
  if(leftEdge >= n-1){
    cout << 0 << endl;
    return 0;
  }
  cout << max(0,rightEdge - leftEdge + 1) << endl;

  return 0;
}
