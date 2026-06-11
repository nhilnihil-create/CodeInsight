#include<iostream>
#include<iomanip>
#include<cstdio>

#include<vector>
#include<queue>
#include<set>
#include<map>
#include<string>

#include<algorithm>
#include<cmath>
#include<numeric>

using namespace std;
typedef long long ll;
template <class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return 1;} return 0;}
template <class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return 1;} return 0;}


/*
vkからvk+1が増加したときはそのまま加速していけばよいのだが、
減少したときには、予め減速していなければならない
*/

int main() {
    int N; cin >> N;
    vector<int> t(N+2,0), v(N+2,0);
    for (int i = 1; i <= N; i++) scanf("%d", &t[i]);
    for (int i = 1; i <= N; i++) scanf("%d", &v[i]); N += 2; 
    int T = 0;
    for (int i = 0; i < N; i++) T += t[i];
    
    
    vector<double> b(2*T+1,1e8);

    int s = 0, e = 0;
    for (int i = 0; i < N; i++) {
        int e = s + 2*t[i];
        for (int j = s; j <= e; j++) chmin(b[j],(double)v[i]);
        for (int j = s; j >= 0; j--) chmin(b[j],(double)v[i]+(s-j)/2.0);
        for (int j = e; j <= 2*T; j++) chmin(b[j],(double)v[i]+(j-e)/2.0);
        s += 2*t[i];
    }

    //for (int i = 0; i <= 2*T; i++) cout << b[i] << " ";
    
    
    double res = 0;
    for (int i = 0; i < 2*T; i++) {
        res += (b[i]+b[i+1])/4.0; 
    }
    printf("%.2lf\n", res);


}
