#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
typedef pair<string, int> P;
bool comp(P &e, P &e2){
    if(e.first != e2.first){
        return e.first < e2.first;
    }
    else return e.second > e2.second;
}
int main(){
  int n;
  cin >> n;
  vector<P> g(n);
  map<P, int> m;
  for(int i = 0; i < n; i++){
    string s;
    int score;
    cin >> s >> score;
    g[i] = P(s, score);
    m[g[i]] = i + 1;
  }
  sort(g.begin(), g.end(), comp);
  for(int i = 0; i < n; i++){
    cout << m[g[i]] << endl;
  }
}
