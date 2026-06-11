#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(void){
    int n, k, x[50], y[50];
    long long ans = 4e18;
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> x[i] >> y[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int xmn = min(x[i], x[j]);
            int xmx = max(x[i], x[j]);
            int ymn = min(y[i], y[j]);
            int ymx = max(y[i], y[j]);
            int zs;
            long long X = xmx - xmn;
            long long Y = ymx - ymn;
            if(k == 2){
                ans = min(ans, X*Y);
                continue;
            }
            vector<int> z;
            for(int l=0;l<n;l++){
                if(l != i && l != j && x[l] >= xmn && x[l] <= xmx){
                    z.push_back(y[l]);
                }
            }
            zs = z.size();
            if(zs + 2 < k) continue;
            sort(z.begin(), z.end());
            for(int l=0;l<zs-k+3;l++){
                Y = max(ymx, z[l+k-3]) - min(ymn, z[l]);
                ans = min(ans, X*Y);
            }
        }
    }
    cout << ans << endl;
}
