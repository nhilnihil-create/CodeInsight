#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int N,C,c;
    cin >> N >> C;

    vector<vector<int>> cost(C,vector<int>(C));
    vector<map<int,int>> mp(3);
    
    for(int i=0;i<C;i++) {
        for(int j=0;j<C;j++) {
            cin >> cost[i][j];
        }
    }

    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin >> c;
            mp[(i+j)%3][c]++;
        }
    }

    // 塗り替えパターンは4060通り
    // 30c3 の塗替え後のカラー配列を持つ
    vector<int> cmin(3);
    int cminsum = INT_MAX,sum;
    vector<int> x(3);
    for(x[0]=0;x[0]<C;x[0]++) {
    for(x[1]=0;x[1]<C;x[1]++) {
        if(x[0]==x[1]) continue;
    for(x[2]=0;x[2]<C;x[2]++) {
        if(x[0]==x[2]) continue;
        if(x[1]==x[2]) continue;
        
    fill(cmin.begin(), cmin.end(), 0);
    sum = 0;
    for(int i=0;i<3;i++) {
        map<int,int>::iterator it = mp[i].begin();
        for(;it!=mp[i].end();it++){
            cmin[i] +=  it->second * cost[it->first-1][x[i]];
        }
        sum += cmin[i];
    }    
    if(cminsum > sum) {
        cminsum = sum;
    }
    
    }}}

    cout << cminsum << endl;

    return 0;
}
