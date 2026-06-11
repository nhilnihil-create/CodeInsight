#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    int N;
    cin >> N;
    vector<bool> so(56000,true);
    vector<int> ans;
    for(int i=2;i<56000;i++){
        if(!so[i]) continue;
        int num=i*2;
        while(num<56000){
            so[num]=false;
            num += i;
        }
    }
    for(int i=2;i<55555;i++){
        if(so[i]&&i%5==1){
            ans.push_back(i);
        }
    }
    rep(i,N) cout << ans[i] << " ";
    cout << endl;
    return 0;
}