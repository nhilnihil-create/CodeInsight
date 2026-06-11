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
    map<char,int> m;
    rep(i,3){
        char c; cin >> c;
        m[c]++;
    }

    if(m['a']==m['b'] && m['b']==m['c']){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}