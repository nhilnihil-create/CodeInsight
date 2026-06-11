#include <bits/stdc++.h>
#define all(vec) vec.begin(),vec.end()
using namespace std;
using ll=long long;
using P=pair<ll,ll>;
const ll INF=1LL<<30;
const ll LINF=1LL<<61;
const double EPS=1e-9;
const int MOD=1e9+7;
int main(){
    int n,m;cin>>n>>m;
    string s;cin>>s;
    vector<vector<int>> G(n);
    vector<int> c1(n),c2(n);
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;--a;--b;
        G[a].push_back(b);
        G[b].push_back(a);
        if(s[a]=='A'){
            c1[b]++;
        }else{
            c2[b]++;
        }
        if(s[b]=='A'){
            c1[a]++;
        }else{
            c2[a]++;
        }
    }
    stack<int> st;
    int co=0;
    for(int i=0;i<n;i++){
        if(c1[i]==0||c2[i]==0){
            st.push(i);
            co++;
        }
    }
    while(!st.empty()){
        int v=st.top();st.pop();
        for(auto e:G[v]){
            if(s[v]=='A'){
                c1[e]--;
                if(c1[e]==0&&c2[e]){
                    st.push(e);
                    co++;
                }
            }else{
                c2[e]--;
                if(c1[e]&&c2[e]==0){
                    st.push(e);
                    co++;
                }
            }
        }
    }
    if(co!=n){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
}
