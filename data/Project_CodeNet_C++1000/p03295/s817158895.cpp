#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REP1(i,n) for(int i=1, i##_len=(n); i<i##_len; ++i)
#define RANGE(i,min,max) for(int i=(min), i##_len=((max)+1); i<i##_len; ++i)

constexpr int max_n = 1e5;
vector<pair<int, int> > wishlist(max_n);

void solve(int N, int M){
    sort(wishlist.rbegin(), wishlist.rend());
    int rFirst = N+1;
    int count = 0;
    REP(i, M) if(wishlist.at(i).second <=rFirst) count++, rFirst=wishlist.at(i).first;
    cout << count << endl;
}

int main(void){
    int N, M;
    cin >> N >> M;
    int i1, i2;
    
    wishlist.resize(M);
    for(auto& w: wishlist) cin >> w.first >> w.second;
    
    solve(N,M);
    return 0;
}
