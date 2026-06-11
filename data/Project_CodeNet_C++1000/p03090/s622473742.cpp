#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

const int INF=1e9;
const int MOD=1e9+7;
bool used[110][110]={};

int main(){
    int N; cin >> N;
    vector<pair<int,int>> ans;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(N%2==0&&i!=j&&(i+j)!=(N+1)&&!used[i][j]){
                ans.push_back({i,j});
                used[i][j]=used[j][i]=true;
            }else if(N%2==1&&i!=j&&(i+j)!=N&&!used[i][j]){
                ans.push_back({i,j});
                used[i][j]=used[j][i]=true;
            }
        }
    }
    cout << ans.size() << endl;
    for(int i=0;i<ans.size();i++){
        cout << ans[i].first << " " << ans[i].second << endl;
    }
}