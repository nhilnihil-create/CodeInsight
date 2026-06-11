#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    int N;
    cin >> N;
    vector<int> B(N);
    rep(i,N) cin >> B[i];
    vector<int> ans;
    
    while(ans.size()<N){
        bool f = true;
        for(int i=B.size()-1;i>=0;i--){
            if(i+1==B[i]){
                //cout << "del:" << i+1 << endl;
                ans.push_back(i+1);
                f=false;
                B.erase(B.begin()+i);
                break;
            }
        }
        if(f){
            cout << -1 << endl;
            return 0;
        }
    }
    
    rep(i,N){
        cout << ans[N-1-i] << endl;
    }
    return 0;
}