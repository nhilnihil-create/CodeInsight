#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    int n;
    cin >> n;
    int a,b;
    vector <int> ans2(n,0);
    vector <int> c(n);
    vector <vector <int>> m(n);

    rep(i,n-1){
        cin >> a >> b;
        m[a-1].push_back(b-1);
        m[b-1].push_back(a-1);
        
    }
    ll ans=0;

    rep(i,n){
        cin >> c[i];
        ans+=c[i];
    }

    sort(c.rbegin(),c.rend());
    ans-=c[0];

    queue <int> q;
    int qq;
    q.push(0);
    int k=0;
    int l;

    while(q.size()!=0){
        qq=q.front();
        q.pop();
        ans2[qq]=c[k];
        ++k;
        l=m[qq].size();
        rep(j,l){
            if(ans2[m[qq][j]]==0){
                q.push(m[qq][j]);
            }
        }

    }

    cout << ans << endl;
    rep(i,n){
        cout << ans2[i] << " "; 
    }

    cout << endl;



    return 0;
}