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
    for(auto & w: wl) cin >> w.second >> w.first;
    sort(wl.begin(), wl.end());
    int leftSec = -INF, count = 0;
    REP(i, M) if(leftSec < wl.at(i).second) count++, leftSec=wl.at(i).first-1;
    cout << count << endl;
}