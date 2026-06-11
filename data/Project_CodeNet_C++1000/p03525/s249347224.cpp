#include<bits/stdc++.h>
#define rep(i, n) for (int i=0;i<(n);i++)
using namespace std;
typedef long long ll;

int INF = 1e9;
 
int main(void){
    int n;
    cin>>n;
    if(n>=25) {
        cout<<0<<endl;
        return 0;
    }
    vector<vector<int> > d(13);
    rep(i, n){
        int a;
        cin>>a;
        d[a].push_back(i);
    }
    d[0].push_back(n);
    int ans = 0;
    if(d[0].size()>1){
        cout<<0<<endl;
        return 0;
    }
    rep(i, 13){
        if(d[i].size()>=3) {
            cout<<0<<endl;
            return 0;
        }
    }
    for(int i = 0;i<(1<<12);i++){
        vector<int>v(12);
        rep(j, 12){
            if((i>>j)&1) v[j]=1;
        }
        int tmp = INF;
        vector<int> vec;
        rep(j, 13){
            if(d[j].size() == 0) continue;
            if(j == 0) vec.push_back(0);
            else if(v[j-1]){
                vec.push_back(24-j);
                if(d[j].size() == 2) vec.push_back(j);
            }
            else {
                vec.push_back(j);
                if(d[j].size() == 2) vec.push_back(24-j);
            }
        }
        rep(i, vec.size()-1){
            for(int j = i+1;j<vec.size();j++){
                tmp = min(tmp, min(abs(vec[i]-vec[j]), 24-abs(vec[i]-vec[j])));
            }
        }
        ans = max(ans, tmp);
    }
    cout<<ans<<endl;
    return 0;
}