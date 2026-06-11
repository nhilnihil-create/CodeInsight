#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool exists(vector<long long> &pos, long long w, long long x, long long y){
    return binary_search(pos.begin(), pos.end(), x + w * y);
}

int main(void){
    long long h, w, n;
    cin >> w >> h >> n;
    vector<long long> pos(n);
    long long x, y;
    for(int i = 0; i < n; i ++){
        cin >> x >> y;
        pos[i] = (x-1) + w * (y-1);
    }
    sort(pos.begin(), pos.end());

    vector<int> d(h, w);
    d[0] = 1;
    for(int j = 1; j < h; j ++){
        d[j] = d[j-1] + 1;
        while(d[j] < w && exists(pos, w, d[j] - 1, j)) d[j] ++;
        if(d[j] == w) break;
    }

    int m = w;
    for(int i = 0; i < n; i ++){
        int x = pos[i] % w;
        if(x < m && x >= d[pos[i] / w]) m = x;
    }
    
    cout << m << "\n";
}
