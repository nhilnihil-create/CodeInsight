#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
typedef long long ll;
const int INF = 1e+9+7;
const int H_MAX = 510;
const int W_MAX = 510;
int H,W;
vector<vector<int>> a(H_MAX,vector<int>(W_MAX,0));

int main(){
    cin >> H >> W;
    rep(i,H){
        rep(j,W){
            cin >> a[i+1][j+1];
        }
    }
    vector<int> ans;

    int cnt=0;
    rep(i,H){
        rep(j,W){
            if(a[i+1][j+1]%2==1){
                if(j+2<=W){
                    ans.push_back(i+1);
                    ans.push_back(j+1);
                    ans.push_back(i+1);
                    ans.push_back(j+2);
                    a[i+1][j+2]++;
                    cnt++;
                }else if(i+2<=H){
                    ans.push_back(i+1);
                    ans.push_back(j+1);
                    ans.push_back(i+2);
                    ans.push_back(j+1);
                    a[i+2][j+1]++;
                    cnt++;
                }
                
            }
        }
    }

    cout << cnt << endl;
    rep(i,ans.size()){
        cout << ans[i];
        if(i%4==3) cout << endl;
        else cout << " ";   
    }
}
