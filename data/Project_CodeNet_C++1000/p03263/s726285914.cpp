#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int H,W; cin>>H>>W;
    vector<vector<int>> A(H,vector<int>(W));
    rep(h,0,H)rep(w,0,W) cin>>A.at(h).at(w);

    vector<vector<int>> Ans;
    rep(h,0,H){
        rep(w,0,W){
            if(h==H-1 && w==W-1) break;

            int X=h,Y,nextX=h,nextY;
            if(w==W-1) nextX++;
            if(h%2){
                Y=W-w-1;
                nextY=max(0,Y-1);
            }else{
                Y=w;
                nextY=min(W-1,Y+1);
            }

            if(A.at(X).at(Y)%2){
                A.at(X).at(Y)--;
                A.at(nextX).at(nextY)++;
                Ans.push_back(vector<int>{X+1,Y+1,nextX+1,nextY+1});
            }
        }
    }

    cout<<Ans.size()<<endl;
    for(auto ans:Ans){
        cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<" "<<ans[3]<<endl;
    }
}