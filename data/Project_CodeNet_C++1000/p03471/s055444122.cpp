#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n,y;
    cin >> n >> y;
    bool a=false;
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n-i; j++){
            if(y==10000*i+5000*j+1000*(n-i-j)){
                cout << i << ' ' << j << ' ' << n-i-j << endl;
                a=true;
            }
            if(a) break;
            if(i==n) cout << -1 << ' ' << -1 << ' ' << -1 << endl;
        }
        if(a) break;
    }
}