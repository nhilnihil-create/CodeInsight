#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(v) v.begin(), v.end()
    
int main(){
    int n,m;
    cin >> n >> m;
    vector < vector <int> > s(m,vector <int>(0));
    vector <int> p(m);

    rep(i,m){
        int k;
        cin >> k;
        rep(j,k){
            int S;
            cin >> S;
            s[i].push_back(S);
        }
    }
    rep(i,m){
        cin >> p[i];
    }
    
    int ans = 0;

    for(int i=0; i<(1<<n); i++){//スイッチの組
        bitset <10> c(i);
        int lamp = 0;
        for(int j=0; j<m; j++){//電球1つずつ検証
            int cntj = 0;
            
            for(int x:s[j]){
                if(c.test(x-1)) cntj ++;
            }

            if(cntj % 2 == p[j]) lamp ++;
        }        
        if(lamp == m) ans ++;
    }
    cout << ans << endl;
}
