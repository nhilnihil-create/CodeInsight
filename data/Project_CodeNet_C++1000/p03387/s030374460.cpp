#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,x) for(int i=0;i<x;i++)
#define put(ans)    cout << ans << endl;

double kaijyo(int n){
    int k(1);
    for(int i=n;i>0;i--){
        k *= i;
    }

    return k;
}

double distance(int x[],int y[],int i,int j){
    int dx = (x[i] - x[j]) * (x[i] - x[j]);
    int dy = (y[i] - y[j]) * (y[i] - y[j]);
    return sqrt(dx+dy);
}

int main(){
    int a,b,c;
    cin >> a >> b >> c;

    int x(min({a,b,c}));
    int z(max({a,b,c}));
    int y(a+b+c-x-z);

    int ans(0);
    if(z%2==x%2 && x%2==y%2){
        int t = min(z-x,z-y);
        ans += t;
        x += t; y += t;
        ans += max(z-x,z-y)/2;
    }else if(x%2==y%2){
        ans = z-y + (y-x)/2;
    }else{
        if(z%2==x%2){
            ans++;  z++;    x++;
            ans += z-y + (y-x)/2; 
        }else{
            ans++;  z++;    y++;
            ans += z-y + (y-x)/2;
        }
    }

    cout << ans << endl;

    return 0;
}