#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
typedef long long ll;
const ll INF = 1e+18;

int main(){
    int A,B;
    int h=100;
    int w=100;
    int cnt;
    cin >> A >> B;
    int large,small;
    large=max(A,B);
    small=min(A,B);
    vector<vector<char>> ans(h,vector<char>(w,'#'));
    cnt=0;
    //A>B前提
    bool flag=false;
    for(int i=0;i<h;i+=4){
        for(int j=0;j<w;j+=4){
            rep(k,3){
                rep(l,3){
                    ans[i+k][j+l]='.';
                }
            }
            cnt++;
            if(cnt==large){
                flag=true;
            }
            if(flag) break;
        }
        if(flag) break;
    }

    cnt=0;
    flag=false;
    for(int i=0;i<h;i+=4){
        for(int j=0;j<w;j+=4){
            if(cnt==small-1){
                flag=true;
            }
            if(flag) break;
            ans[i+1][j+1]='#';
            cnt++;
            
        }
        if(flag) break;
    }

    if(A<B){
        rep(i,h){
            rep(j,w){
                if(ans[i][j]=='#') ans[i][j]='.';
                else ans[i][j]='#';
            }
        }
    }
    cout << h << " " << w << endl;
    rep(i,h){
        rep(j,w){
            cout << ans[i][j];
        }
        cout << endl;
    }
    
    
    



}
