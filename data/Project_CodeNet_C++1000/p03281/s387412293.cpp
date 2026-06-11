
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define all(v) v.begin(), v.end()
#define F first
#define S second
#define INF 1000000000000
#define MOD 10000007
#define PI 3.14159265359
#define dij priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>
typedef long long ll;
//
int get_ans(int n){
    int ans=1;
    if(n%2==0||n==1)ans=0;
    else{
        int co=0,t=3;
        vector<int> v;
        while(n>1){
            if(n%t==0){
                n/=t;
                co++;
            }  
            if(n%t!=0){
                t++;
                v.push_back(co);
                co=0;
            }
        }
        rep(i,v.size()){
            ans*=v[i]+1;
        }
    }
    return ans;
}
int main(){
    int n;cin>>n;
    int ans=0;
    FOR(i,1,n){
        if(get_ans(i)==8)ans++;
//        cout<<get_ans(i)<<endl;
    }
    cout<<ans<<endl;
}
