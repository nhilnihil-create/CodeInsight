#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define put(i) cout<<fixed<<i<<endl
using namespace std;
using ll = long long;

int main(){
    int a, b; cin >> a >> b;
    int h = 0;
    
    for(int i = 1;; i++){
        h += i;
        if(i == b - a){
            put(h - a - i);
            return 0;
        }
    }
}