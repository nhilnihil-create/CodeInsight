//#include "pch.h"
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <limits.h>
#include <string>
#include <deque>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

#define rip(i, n, s) for (int i = (s);i < (int)( n ); i++)
#define mpa make_pair
#define all(a) (a).begin(), (a).end()

struct zone{
    double v,t,num;
    zone(double _v, double _t, double _num){v = _v;t = _t;num = _num;}
};

bool operator>(const zone &left, const zone &right) {return left.v > right.v;}

int main(){
    int n; cin >> n;
    vector<double> t(n + 2), v(n + 2);
    rip(i, n+1, 1) cin >> t[i];
    rip(i, n+1, 1) cin >> v[i];
    priority_queue<zone, vector<zone>, greater<zone>> pq;
    v[1] = min(v[1],t[1]); v[n] = min(v[n], t[n]); 
    rip(i, n+1, 1) pq.push(zone(v[i], t[i], i));
    vector<bool> ju(n + 2, false);
    while(pq.size()){
        zone now = pq.top(); pq.pop();
        if(ju[now.num]) continue;
        ju[now.num] = true;
        if(v[now.num - 1] > v[now.num] + t[now.num - 1]){
            v[now.num - 1] = v[now.num] + t[now.num - 1];
            pq.push(zone(v[now.num - 1], t[now.num - 1], now.num - 1));
        }
        if(v[now.num + 1] > v[now.num] + t[now.num + 1]){
            v[now.num + 1] = v[now.num] + t[now.num + 1];
            pq.push(zone(v[now.num + 1], t[now.num + 1], now.num + 1));
        }
    }
    double ans = 0;
    auto squ = [](double x) {return x * x;};
    rip(i, n + 1, 1){
        double left = min(v[i - 1], v[i]), right = min(v[i + 1],v[i]);
        if(t[i] - v[i]*2 + left + right < 0){
            double ab = abs(left -right);
            ans += squ(t[i] - ab) / 4;
            ans += (t[i] * 2 - ab) * ab / 2;
            ans += t[i] * min(left, right);
        }
        else{
            ans += v[i] * t[i];
            ans -= squ(v[i] - left) / 2;
            ans -= squ(v[i] - right) / 2;
        }
        //printf("%f %f %f %f %f\n", left, v[i], right, t[i], ans);
    }
    printf("%.03f\n",ans);
}