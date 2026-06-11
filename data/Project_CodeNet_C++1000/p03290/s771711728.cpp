#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD=1e9+7;

int main() {
    int d,g;
    cin>>d>>g;
    pair<int,int> P[10];
    rep(i,d) cin>>P[i].first>>P[i].second;
    int ans=1001;
    for(int bit=0;bit<(1<<d);bit++){//コンプリートする数でbit全探索
        int point=0;
        int solved=0;
        rep(i,d) if(bit&(1<<i)){
            point+=100*(i+1)*P[i].first+P[i].second;
            solved+=P[i].first;
        }
        //cout<<solved<<" "<<point<<endl;
        if(point>=g) ans=min(ans,solved);
        else{
            for(int i=d-1;i>=0;--i){//残りは得点の高い方から解く
                if(bit&(1<<i)) continue;
                if(point+(i+1)*100*(P[i].first-1)<g){
                    //効率悪そうだけどコンプリートしない
                    solved+=P[i].first-1;
                    point+=(i+1)*100*(P[i].first-1);
                }
                else{
                    //gを超えるのにi*100点の問題を何問解けばいいか
                    int need=(g-point+(i+1)*100-1)/((i+1)*100);
                    solved+=need;
                    point+=(i+1)*100*need;
                }
                //cout<<" "<<solved<<" "<<point<<endl;
                if(point>=g) break;
            }
            if(point>=g) ans=min(ans,solved);
        }
    }
    cout<<ans<<endl;
    return 0;
}