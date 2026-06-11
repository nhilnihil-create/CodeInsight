#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
template<typename T1,typename T2> bool chmin(T1 &a,T2 b){if(a<=b)return 0; a=b; return 1;}
template<typename T1,typename T2> bool chmax(T1 &a,T2 b){if(a>=b)return 0; a=b; return 1;}
int dx[4]={0,1,-1,0};
int dy[4]={1,0,0,-1};
long double eps = 1e-6;
long double pi = acos(-1);


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    int n,k;
    cin>>n>>k;
    if((1<<n) <= k){
        cout << -1 << endl;
        return 0;
    }
    if(n==1){
        if(k)cout << -1 << endl;
        else cout << "0 0 1 1" << endl;
        return 0;
    }
    for(int i=0;i<(1<<n);i++){
        if(i==k)continue;
        cout << i << " ";
    }
    cout << k << " ";
    for(int i=(1<<n)-1;i>=0;i--){
        if(i==k)continue;
        cout << i << " ";
    }
    cout << k << endl;

    
}