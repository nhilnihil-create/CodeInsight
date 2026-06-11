#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
/*既に塗った色の配列　tuple(親、子、その間の辺の色)の配列
  を用意
*/
struct edge{
    int to,color;
};

using Graph = vector<vector<edge>>;

int main() {
    string S;
    cin >> S;
    int K;
    cin >> K;
    vector<string> vec;
    set<string> s;
    for(int i = 0;i<S.size();i++){
        for(int j = 0;j<S.size()-i;j++){
          if(j+1 > K) break;
          s.insert(S.substr(i,j+1));
        }
    }
    for(auto value : s){
        vec.push_back(value);
    }
    sort(vec.begin(),vec.end());
    /*rep(i,vec.size()){
      cout << vec[i] << endl;
    }*/
    cout << vec[K-1] << endl;
  }