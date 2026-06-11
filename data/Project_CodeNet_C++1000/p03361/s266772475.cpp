#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main() {
    int h,w;cin>>h>>w;
    vector<string> s(h);
    rep(i,h)cin>>s[i];
    
    vector<int> di={-1,0,1,0};
    vector<int> dj={0,1,0,-1};
    
    rep(i,h)rep(j,w){
        if(s[i][j]=='.')continue;
        
        bool ok = false;
        
        rep(k,4){
            int ni = i+di[k];
            int nj = j+dj[k];
            
            if(ni<0 || ni>=h)continue;
            if(nj<0 || nj>=w)continue;
            
            if(s[ni][nj]=='#')
                ok = true;
        }
        
        if(!ok){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}