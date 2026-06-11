#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vv = vector<vi>;

int main() {
    int h,w;cin>>h>>w;
    vv a(h, vi (w));
    
    int codd = 0;
    
    rep(i,h)rep(j,w){
        cin>>a[i][j];
        codd += a[i][j]%2;
    }
    
    codd /= 2;
    
    int c=0;
    int ni=0, nj=0;
    
    bool move = false;
    
    vv ans;vi o;
    
    while(c<codd){
        if(move==false && a[ni][nj]%2){//start
            ans.push_back(o);
            ans.back().push_back(ni+1);
            ans.back().push_back(nj+1);
            move = true;
        }else if(move==true && a[ni][nj]%2){//end
            move = false;
            c++;
        }else if(move==true && a[ni][nj]%2==0){
            ans.push_back(o);
            ans.back().push_back(ni+1);
            ans.back().push_back(nj+1);
        }
        
        
        if(ni%2==0 && nj<w-1)
            nj++;
        else if(ni%2==0 && nj==w-1)
            ni++;
        else if(ni%2==1 && nj>0)
            nj--;
        else if(ni%2==1 && nj==0)
            ni++;
        
        
        if(move==true){//during move
            ans.back().push_back(ni+1);
            ans.back().push_back(nj+1);
        }
    }
    
    
    cout << ans.size() << endl;
    rep(i,ans.size()){
        rep(j,4){
            cout << ans[i][j];
            if(j==3)cout << endl;
            else cout << " ";
        }
    }
    return 0;
}