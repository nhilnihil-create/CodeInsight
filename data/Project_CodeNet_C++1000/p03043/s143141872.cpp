#include <bits/stdc++.h>

using namespace std;

int count(int x, int k){
    int res = 0;
    while(x < k){
        x *= 2;
        res++;
    }
    return res;
}
double pow(int x){
    double res = 1.0;
    for(int i = 0; i < x; i++){
        res *= 0.5;
    }
    return res;
}
int main(){
    int n, k;
    cin >> n >> k;
    double pro = 0;
    if(k <= n){
        for(int i = 1; i < k; i++){
            pro += 1 / static_cast<double>(n) * pow(count(i, k));
        }
        pro += (n - k + 1) / static_cast<double>(n);
    }else{
        for(int i = 1; i <= n; i++){
            pro += 1 / static_cast<double>(n)* pow(count(i, k));
        }
    }
    printf("%.12lf\n", pro);
}
