#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int nax = 9;
const int MOD = 1e9+7;

int a,b,c,n;
vector<int> v(nax);

int dfs(int ind, int p, int q, int r){
    if(ind==n){
        if(min({p,q,r})>0){
            return (abs(a-p)+abs(b-q)+abs(c-r) - 30);
        }
        else{
            return MOD;
        }
    }
    int ans1 = dfs(ind+1, p,q,r);
    int ans2 = dfs(ind+1, p+v[ind], q,r)+10;
    int ans3 = dfs(ind+1, p, q+v[ind],r)+10;
    int ans4 = dfs(ind+1, p,q, r+v[ind])+10;
    return min({ans1, ans2, ans3, ans4});
}

int main(){
    cin>>n>>a>>b>>c;

    v.assign(n, 0);

    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    int ans = dfs(0,0,0,0);

    cout<<ans<<endl;

    return 0;
}