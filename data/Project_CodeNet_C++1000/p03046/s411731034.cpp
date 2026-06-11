#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int m,k;cin >> m >> k;
    
    if(k >= (1 << m)){
        cout << -1 << '\n';
        return 0;
    }

    if(m == 0){
        cout << "0 0" << '\n';
        return 0;
    }
    if(m == 1){
        if(k == 0)cout << "1 1 0 0" << '\n';
        else cout << -1 << '\n';
        return 0;
    }else{
        for(int i = 0;i < (1 << m);i++){
            if(i != k)cout << i << ' ';
        }
        cout << k << ' ';
        for(int i = (1 << m) - 1;i >= 0;i--){
            if(i != k)cout << i << ' ';
        }
        cout << k << '\n';
    }
}