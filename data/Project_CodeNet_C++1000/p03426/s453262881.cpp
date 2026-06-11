#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int h,w,d;
    cin >> h >> w >> d;
    int x[90001];
    int y[90001];
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            int a;
            cin >> a;
            x[a]=i;
            y[a]=j;
        }
    }

    int dis[90001];
    for(int i=d+1;i<=h*w;i++){
        dis[i] = dis[i-d] + abs(x[i]-x[i-d]) + abs(y[i]-y[i-d]);
    }
    int q;
    cin >> q;
    for(int i=0;i<q;i++){
        int l,r;
        cin >> l >> r;
        cout << dis[r] - dis[l]<< endl;
    }
}