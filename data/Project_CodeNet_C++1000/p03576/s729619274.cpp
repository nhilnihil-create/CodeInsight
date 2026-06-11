#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include <queue>
#include <deque>
#include <cmath>
#include <iomanip>
#include <cstdio>
#include <limits>
#include <climits>

using namespace std;

int main(){
    int n, k; cin >> n >> k;
    vector<pair<long long, long long>> xys(n);
    for(int i=0; i<n; ++i){
        cin >> xys[i].first >>xys[i].second;
    }
    long long ans=numeric_limits<long long>::max();
    vector<int> index(4);
    for(index[0]=0; index[0]<n; ++index[0]){
        for(index[1]=0; index[1]<n; ++index[1]){
            for(index[2]=0; index[2]<n; ++index[2]){
                for(index[3]=0; index[3]<n; ++index[3]){
                    long long x1=xys[index[0]].first, x2=xys[index[0]].first;
                    long long y1=xys[index[0]].second, y2=xys[index[0]].second;
                    for(int i=1; i<4; ++i){
                        x1=min(x1, xys[index[i]].first);
                        x2=max(x2, xys[index[i]].first);
                        y1=min(y1, xys[index[i]].second);
                        y2=max(y2, xys[index[i]].second);
                    }
                    int cnt=0;
                    for(int ki=0; ki<n; ++ki){
                        long long x3=xys[ki].first, y3=xys[ki].second;
                        if(x1<=x3 && x3<=x2 && y1<=y3 && y3<=y2) ++cnt;
                    }
                    if(cnt==k) ans=min(ans, (x2-x1)*(y2-y1));
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
