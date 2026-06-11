#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

#define mod 1e9+7
#define ll long long int
#define epsilon 1e-7

double min(double x, double y){
    if(x<y)return x;
    return y;
}

int t[100];
int v[100];
double realv[20000];
int tsum[101];
int main(void){
    int n;
    scanf("%d", &n);
    int tt = 0;
    tsum[0] = 0;
    for(int i = 0;i < n;i++){
        scanf("%d", &t[i]);
        tt += t[i];
        tsum[i+1] = tt;
    }
    for(int i = 0;i < n;i++){
        scanf("%d", &v[i]);
    }
    double ans = 0;
    for(int i = 0;i < n;i++){
        for(int j = tsum[i];j < tsum[i+1];j++){
            double real = min(j, min(tsum[n]-j, v[i]));
            for(int k = 0;k < n;k++){
                if(k < i){
                    real = min(real, v[k] + j - tsum[k+1]);
                }
                if(k > i){
                    real = min(real, v[k] + tsum[k] - j);
                }
            }
            double half = min((double)j + 0.5, min((double)tsum[n]-(double)j - 0.5, (double)v[i]));
            for(int k = 0;k < n;k++){
                if(k < i){
                    half = min(half, (double)v[k] + (double)j + 0.5 - (double)tsum[k+1]);
                }
                if(k > i){
                    half = min(half, (double)v[k] + (double)tsum[k] - (double)j - 0.5);
                }
            }
            ans += real / 2.0 + half / 2.0;
        }
    }
    printf("%lf\n", ans);
    return 0;
}
