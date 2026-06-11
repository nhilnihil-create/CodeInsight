#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll N;
vector<ll> ans;


void dfs(ll remain,ll t){
    // cerr <<"remain=" << remain<<"t="<<t << endl;
    if(remain==0){
        //出力
        sort(ans.rbegin(),ans.rend());
        int maxV =ans[0];
        int t=0;
        for(int i=maxV;i>=0;--i){
            if(t<ans.size()&&ans[t] == i){
                t++;
                cout << 1;
            }else{
                cout <<0;
            }
        }
        cout <<endl;
        return;
    }
    if(abs(remain)%2 != 0){
        ans.push_back(t);
        t++;
        if(t %2 ==1){
            dfs((remain-1)/2,t);
        }else{
            dfs((remain+1)/2,t);
        }
    }else{
        t++;
        dfs(remain/2,t);
    }
}

int main() {
    cin >> N;
    if(N==0){
        cout << 0 << endl;
        return 0;
    }
    
    dfs(N,0);


    return 0;
}