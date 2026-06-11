#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main() {
    int h,w;cin>>h>>w;
    vector<string> s(h);
    rep(i,h)cin>>s[i];
    
    vector<int> di={-1,-1,0,1,1,1,0,-1};
    vector<int> dj={0,1,1,1,0,-1,-1,-1};
    
    vector<string> t(h);
    rep(i,h)rep(j,w){
        if(s[i][j]=='#'){
            t[i].push_back('#');
            continue;
        }
        
        int count = 0;
        
        rep(k,8){
            int ni = i+di[k];
            int nj = j+dj[k];
            if(ni<0 || ni>=h)continue;
            if(nj<0 || nj>=w)continue;
            
            if(s[ni][nj]=='#')
                count++;
        }
        
        t[i].push_back((char)count+'0');
        
    }
    
    rep(i,h)cout<<t[i]<<endl;
    return 0;
}