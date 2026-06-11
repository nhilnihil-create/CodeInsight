#include <bits/stdc++.h>
using namespace std;

int main(){
    int K,n;
    cin >> n >> K;
    pair<long long,long long> p[n],q[n];
    for(int i=0; i<n; i++){
        long long x,y;
        cin >> x >> y;
        p[i] = make_pair(x,y);
        q[i] = make_pair(y,x);
    }
    sort(p,p+n);
    sort(q,q+n);
    long long ans = 4000000000000000000;
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            for(int k=0; k<n-1; k++){
                for(int l=k+1; l<n; l++){
                    int cnt=0;
                    long long u=q[l].first,d=q[k].first;
                    for(int m=i; m<=j; m++){
                        if(p[m].second <= u && p[m].second >= d) cnt++;
                    }
                    if(cnt == K) ans = min(ans,(u-d)*(p[j].first-p[i].first));
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
