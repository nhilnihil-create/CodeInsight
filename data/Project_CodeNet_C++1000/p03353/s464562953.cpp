#include <bits/stdc++.h>
#define int long long
using namespace std;


signed main(){
    string S;cin>>S;
    int K;cin>>K;
    int N=S.size();
    set<string> dict;
    for(int i=1;i<=K;i++){
        for(int j=0;j<N-i+1;j++){
            string T="";
            for(int p=0;p<i;p++)T+=S[j+p];
            dict.insert(T);
        }
    }
    vector<string> ans;
    for(auto T:dict){
        ans.push_back(T);
    }
    sort(ans.begin(),ans.end());    
    cout<<ans[K-1]<<endl;
}