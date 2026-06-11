//#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
//using namespace atcoder;
typedef long long ll;
typedef pair<ll,ll> P;
const ll MOD=1000000007;
int n;
int d[200005];
int m;
int t[200005];
int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin>>n;
    map<int,int> M;
    for(int i=0;i<n;i++){
        cin>>d[i];
        M[d[i]]++;
    }
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>t[i];
        if(M[t[i]]==0){
            cout<<"NO"<<endl;
            return 0;
        }else{
            M[t[i]]--;
        }
    }
    cout<<"YES"<<endl;
    
}
