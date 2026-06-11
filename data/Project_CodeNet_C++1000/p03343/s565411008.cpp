#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF=1LL<<60;
const int inf=1<<30;
const int mod=1e9+7;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,K,q;cin >> n >> K >> q;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int ans=inf;
    for(int i=0;i<n;i++){
        int cnt=0,m=-1;
        vector<int> b(n);
        for(int j=0;j<n;j++){
            if(a[j]<a[i]){
                if(m==-1){
                    continue;
                }
                b[m]=cnt;
                m=-1;
                cnt=0;
            }
            else{
                if(m==-1){
                    m=j;
                }
                cnt++;
            }
        }
        if(m!=-1){
            b[m]=cnt;
        }
        vector<int> u;
        for(int j=0;j<n;j++){
            if(!b[j]){
                continue;
            }
            vector<int> v;
            for(int l=0;l<b[j];l++){
                v.push_back(a[j+l]);
            }
            sort(v.begin(),v.end());
            for(int l=0;l<b[j]-K+1;l++){
                u.push_back(v[l]);
            }
            j+=b[j];
        }
        if(u.size()<q){
            continue;
        }
        sort(u.begin(),u.end());
        int t=0;
        for(int j=0;j<q;j++){
            chmax(t,u[j]);
        }
        chmin(ans,t-a[i]);
    }
    cout << ans << endl;
}