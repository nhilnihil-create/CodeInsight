#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
using namespace std;
typedef long long ll;
int INF = (1LL << 30) - 1;
int MOD = 1e9+7;
main(){
    int N;
    cin >> N;
    vector<int> V(N);
    rep(i,0,N)cin >> V[i];
    map<int,int> mp;
    rep(i,0,N)mp[V[i]]++;
    for(auto p:mp)if(p.second > 2 || p.first == 0){
        cout << 0 << endl;
        return 0;
    }
    int maxi = 0;
    set<int> st;
    vector<int> vec;
    rep(i,0,N){
        if(mp[V[i]] == 1){
            vec.push_back(V[i]);
        }else{
            st.insert(V[i]);
            st.insert(24 - V[i]);
        }
    }
    int M = vec.size();
    
    if(V[0] == 0 && N == 1){
        cout << 0 << endl;
        return 0;
    }
    st.insert(0);
    rep(i,0,1 << M){
        rep(j,0,M){
            if(i & (1 << j)){
                st.insert(vec[j]);
            }else{
                st.insert(24 - vec[j]);
            }
        }
        vector<int> tmp;
        for(auto itr:st)tmp.push_back(itr);
        int mini = INF;
        rep(ii,0,tmp.size())rep(jj,ii+1,tmp.size()){
            int dif = abs(tmp[ii] - tmp[jj]);
            mini = min({mini, dif, 24 - dif});
        }
        rep(j,0,M){
            if(i & (1 << j)){
                st.erase(vec[j]);
            }else{
                st.erase(24 - vec[j]);
            }
        }
        maxi = max(maxi, mini);
    }
    //assert(false);
    cout << maxi << endl;
}