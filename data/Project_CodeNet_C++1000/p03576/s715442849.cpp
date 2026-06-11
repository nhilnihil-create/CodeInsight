#include <bits/stdc++.h>
using namespace std;
const long long int INF = 4 * 1e18;

int main(){
    int n, k;
    cin >> n >> k;

    vector<long long int> x(n), y(n);
    vector<pair<long long int, long long int>> point(n);
    for(int i=0; i<n; i++){
        cin >> x[i] >> y[i];
        point[i] = make_pair(x[i],y[i]);
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    long long int ans = INF;
    for(int i=0; i<n; i++){// left
        for(int j=i+1; j<n; j++){// right
            for(int l=0; l<n; l++){// lower
                for(int m=l+1; m<n; m++){// upper
                    int count = 0;
                    for(int p=0; p<n; p++){// points
                        if(x[i] <= point[p].first  && point[p].first  <= x[j]
                        && y[l] <= point[p].second && point[p].second <= y[m]){
                            count += 1;
                        }
                    }
                    if(count == k) ans = min(ans, (x[i] - x[j]) * (y[l] - y[m]));
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}