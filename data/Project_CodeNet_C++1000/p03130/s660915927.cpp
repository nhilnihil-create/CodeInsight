#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define per(i,n) for(int i=(n)-1; i>=0; i--)
using namespace std;
using vi = vector<int>;
using vv = vector<vi>;

int main(){
    vi c(4);
    rep(i,6){
        int b;
        cin >> b;
        b--;
        c[b]++;
    }
    rep(i,4){
        if(c[i]==3){
            cout << "NO" << endl;
            return 0;
        }
    }
    
    cout << "YES" << endl;
    
    return 0;
}