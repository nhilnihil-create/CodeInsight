#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()


int main(){
    int n;
    cin>>n;
    vector<int> b;
    rep(i,n){
        int bb;
        cin>>bb;
        b.push_back(bb);
    }

    vector<int> ans;
    vector<int> c;
    rep(i,n){
        int id=-1;
        for(int j=b.size()-1;j>=0;j--){
            if(j+1==b[j]){
                id=j;
                ans.push_back(b[j]);
                break;
            }
        }
        if(id==-1){
            cout<<-1<<endl;
            return 0;
        }
        c.clear();
        rep(j,b.size()){
            if(j==id) continue;
            c.push_back(b[j]);
        }
        b.clear();
        rep(j,c.size()){
            b.push_back(c[j]);
        }
    }

    reverse(all(ans));
    rep(i,n) cout<<ans[i]<<endl;
}
