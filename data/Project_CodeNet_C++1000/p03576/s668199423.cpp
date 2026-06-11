#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> x(n);
    vector<int> y(n);
    for(int i=0;i<n;++i){
        cin >> x[i] >> y[i];
    }
    long long ans=LLONG_MAX;
    for(int xi=0;xi<n;++xi){
        for(int xj=0;xj<n;++xj){
            if(x[xi]>=x[xj])
                continue;
            for(int yi=0;yi<n;++yi){
                for(int yj=0;yj<n;++yj){
                    if(y[yi]>=y[yj])
                        continue;
                    int count=0;
                    for(int i=0;i<n;++i){
                        if(x[xi]<=x[i] && x[i]<=x[xj] && y[yi]<=y[i] && y[i]<=y[yj])
                            ++count;
                    }
                    if(count>=k)
                        ans = min(ans, (long long)(x[xj]-x[xi])*(y[yj]-y[yi]));
                }
            }
        }
    }
    cout << ans;
    return 0;
}