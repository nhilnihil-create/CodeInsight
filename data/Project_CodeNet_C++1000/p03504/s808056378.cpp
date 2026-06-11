#include <bits/stdc++.h>
using namespace std;

#define vint vector<int> 
#define vbool vector<bool>
#define vvint vector<vector<int>>

#define rep(a, b, c) for(int (a)=(b); (a)<(c); (a)++)
#define all(a) (a).begin(), (a).end()

int main(){

    int n,cn; cin>>n>>cn;
    vector<int> s(n), t(n), c(n);
    rep(i, 0, n){
        cin>>s[i]>>t[i]>>c[i];
    }
    
    long t_max = pow(10, 5) * 2;
    
    vector<vector<int>> schedule(cn, vector<int>(t_max));
    rep(i, 0, n){
        rep(j, s[i]*2-1, t[i]*2){
    
            schedule[c[i]-1][j] = 1;
    
        }
    }
    

    int max = 0;
    rep(i, 0, t_max){
        int count = 0;
        rep(j, 0, cn){
            count+= schedule[j][i];
        }
        if(count > max) max = count;
    }

    cout << max;
}