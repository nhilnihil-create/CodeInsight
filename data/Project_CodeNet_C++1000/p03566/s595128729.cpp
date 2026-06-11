#include <iostream>
#include <algorithm>
using namespace std;
 
int main()
{
    int n;
    cin >> n;
    int t[102], v[102];
    int l[102], r[102];
    int pt[102];
    int d[40003];
    l[0] = 0;
    pt[0] = 0;
    for(int i = 1; i <= n; i++){
        cin >> t[i];
        t[i] *= 2;
        pt[i] = pt[i - 1] + t[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> v[i];
        v[i] *= 2;
        l[i] = min(l[i - 1], v[i] - pt[i]);
    }
    r[n] = 0;
    for(int i = n - 1; i >= 0; i--){
        r[i] = min(r[i + 1], v[i + 1] - (pt[n] - pt[i]));
    }
    for(int i = 1; i <= n; i++){
        for(int j = pt[i - 1]; j <= pt[i]; j++){
            d[j] = min(l[i - 1] + j, r[i] + (pt[n] - j));
            d[j] = min(d[j], v[i]);
        }
    }
    double ans = 0;
    for(int i = 0; i < pt[n]; i++){
        ans += d[i] + d[i + 1];
    }
	printf("%.15f\n", ans / 8.0);
}