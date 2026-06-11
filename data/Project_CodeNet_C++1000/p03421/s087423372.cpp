#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;
const ll INF=1000000010;
const ll MOD=1000000007;
const ll LINF=4000000000000000000;
const long double EPS=1e-9;
typedef pair<int,int> P;
int main(){
    ll n,a,b;cin>>n>>a>>b;
    if(a+b-1>n||a*b<n){
        cout<<-1<<endl;
        return 0;
    }
    int s=0;
    for(int i=1;i<=a;i++){
        int st=s+b,en=s+1;
        if(n<a-i+st){
            st=n-(a-i);
        }
        for(int j=st;j>=en;j--){
            cout<<j<<" ";
            s++;
        }
    }
    cout<<endl;
}