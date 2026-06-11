#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define REP(i,n) for (int i=0;i<(n);++i)
typedef long long ll;

int N;
ll dp[21000];

struct Block{
    int w,s,v;
    Block(int w,int s,int v) : w(w),s(s),v(v){}
    bool operator<(const Block &b) const { return w+s < b.w+b.s;}
};
vector<Block> blocks;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cin >> N;
    REP(i,N){
        int w,s,v;
        cin >> w >> s >> v;
        blocks.emplace_back(w,s,v);
    }
    sort(blocks.begin(),blocks.end());
    REP(i,N){
        for(int j = blocks[i].s; j>=0; --j){
            if(dp[j+blocks[i].w] < dp[j] + blocks[i].v){
                dp[j+blocks[i].w] = dp[j] + blocks[i].v;
            }
        }
    }
    cout << *(max_element(dp,dp+21000)) << endl;
    return 0;
}