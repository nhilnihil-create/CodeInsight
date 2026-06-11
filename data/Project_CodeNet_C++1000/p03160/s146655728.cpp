#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iostream>
using namespace std;
#define mx 100001
int main(){
    int cost[mx],h[mx];
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> h[i];
    }
    cost[0] = 0;
    for(int i = 1; i < n; i++){
        cost[i] = min(abs(h[i] - h[i - 1]) + cost[i - 1], abs(h[i] - h[i - 2]) + cost[i - 2]);
    }
    cout << cost[n - 1] << endl;
    return 0;
}