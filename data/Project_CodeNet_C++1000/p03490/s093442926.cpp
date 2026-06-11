#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <functional>
#include <numeric>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <limits>
#include <iomanip>
#include <bitset>
#include <queue>

using namespace std;
typedef long long ll;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
#define REP(i, n) for(int i = 0;i < n;i++)
const long long INF = 1LL << 60;

int MOD = 1000000007;

int main(){
    std::ios_base::sync_with_stdio(false);

    string s; int x,y;
    cin >> s >> x >> y;

    vector<int> h; vector<int> v;

    int start = 0;
    while(start<s.length()&&s[start]=='F'){
      start++;
    }

    x-=start;

    bool hor = true;

    for(int j=start; j<s.length(); ++j){
      if(s[j]=='T'){

        hor = !hor;
      }else{
        int cnt=0;
        while(j<s.length()&&s[j]=='F'){
          cnt++; j++;
        }
        --j;
        if(hor) h.push_back(cnt);
        else v.push_back(cnt);
      }
    }

    vector<bool> ph(8020, false); ph[0]=true;
    vector<bool> pv(8020, false); pv[0]=true;

    REP(i,h.size()){
      vector<bool> t(8020, false);
      REP(j, 8020){
        if(ph[j]){
          t[j+h[i]] = true;
          t[abs(j-h[i])] = true;
        }
      }
      ph = t;
    }

    REP(i,v.size()){
      vector<bool> t(8020, false);
      REP(j, 8020){
        if(pv[j]){
          t[j+v[i]] = true;
          t[abs(j-v[i])] = true;
        }
      }
      pv = t;
    }

    if(ph[abs(x)] && pv[abs(y)]) cout << "Yes" << endl;
    else cout<<"No"<<endl;

    return 0;
}
