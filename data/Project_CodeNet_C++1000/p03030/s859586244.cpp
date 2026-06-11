#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define intll int long long
const int INF = 1e9;
const int MOD = 1e9 + 7;

int main() {
  int n ; 
  cin >> n ; 
  vector<tuple<string,int,int>> data ;
  
  rep(i,n){
    string s ; 
    int p ; 
    cin >> s >> p ; 
    data.push_back(make_tuple(s,100-p,i+1));
  }
  sort(all(data)) ;
       
  for(auto p :data){
    string a ;
    int b, c ;
    tie(a,b,c) = p ;
    cout << c <<endl ;
  }

}
