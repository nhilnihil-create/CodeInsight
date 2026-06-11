#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using vi = vector<int>;
using vv = vector<vi>;

int main(){
    int n;cin>>n;
    
    vv xyh(n, vi (3));
    rep(i,n)rep(j,3)cin>>xyh[i][j];
    
    for(int cx=0; cx<=100; cx++){
        for(int cy=0; cy<=100; cy++){
            int ch;
            rep(i,n){
                if(xyh[i][2]==0)continue;
                ch = xyh[i][2] + abs(xyh[i][0]-cx) + abs(xyh[i][1]-cy);
                break;
            }
            
            bool ok = true;
            rep(i,n){
                int h = max(0, ch - abs(xyh[i][0]-cx) - abs(xyh[i][1]-cy));
                if(xyh[i][2]==h)continue;
                ok = false;
                break;
            }
            if(ok){
                cout << cx <<" "<< cy <<" "<< ch << endl;
                return 0;
            }
        }
    }
}