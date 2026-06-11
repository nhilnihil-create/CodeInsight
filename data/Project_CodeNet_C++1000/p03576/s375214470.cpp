/*|In The Name Of Allah|*/

#include <bits/stdc++.h>

using namespace std;

const long longN = 1e2+5;

long long n;
long long k;
vector < pair < long long, long long> > xy;

long long getA(long long a , long long b , long long c , long long d){
    long long X1 = min( min(xy[a].first , xy[b].first) , min(xy[c].first , xy[d].first));
    long long X2 = max( max(xy[a].first , xy[b].first) , max(xy[c].first , xy[d].first));
    long long Y1 = min( min(xy[a].second , xy[b].second) , min(xy[c].second , xy[d].second));
    long long Y2 = max( max(xy[a].second , xy[b].second) , max(xy[c].second , xy[d].second));
    return (X2 - X1) * (Y2 - Y1);

}

long long getX(long long a , long long b , long long c , long long d){
    long long X1 = min( min(xy[a].first , xy[b].first) , min(xy[c].first , xy[d].first));
    long long X2 = max( max(xy[a].first , xy[b].first) , max(xy[c].first , xy[d].first));
    long long Y1 = min( min(xy[a].second , xy[b].second) , min(xy[c].second , xy[d].second));
    long long Y2 = max( max(xy[a].second , xy[b].second) , max(xy[c].second , xy[d].second));
    long long cntpoints = 0;
    for(long long i = 0; i < n; i++){
        if(X1 <= xy[i].first && xy[i].first <= X2 && Y1 <= xy[i].second && xy[i].second <= Y2)
            cntpoints++;
    }
    return cntpoints;
}

int main(){
    scanf("%lld%lld" , &n , &k);
    for(long long i = 1; i <= n; i++){
        long long x , y;
        cin >> x >> y;
        xy.push_back({x , y});
    }
    long long area = 1LL << 63 - 1;
    for(long long a = 0; a < n; a++){
        for(long long b = 0; b < n; b++){
            for(long long c = 0; c < n; c++){
                for(long long d = 0; d < n; d++){
                    if(getX(a , b , c , d) >= k){
                        area = min(area , getA(a , b , c , d));
                    }
                }
            }
        }
    }
    cout << area << endl;
}
