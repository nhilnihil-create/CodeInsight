#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REP1(i,n) for(int i=1, i##_len=(n); i<i##_len; ++i)
#define RANGE(i,min,max) for(int i=(min), i##_len=((max)+1); i<i##_len; ++i)
constexpr int m_max=1e5;
vector<pair<int,int>> wl(m_max);
int N,M;
constexpr int INF = 1e6; 
int main(){
    cin >> N >> M;
    wl.resize(M);

   for(auto& w: wl) cin >> w.first >> w.second;
   int res = 0, right = INF;
   sort(wl.rbegin(), wl.rend());
   REP(i,M) if(wl.at(i).second <= right) res++, right=wl.at(i).first;
   cout << res << endl;
}