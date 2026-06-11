#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
int main(){
    int n;
    cin>>n;
    map<int,int> v1,v2;
    rep(i,n){
        int x;
        cin>>x;
        if(i%2==0) v1[x]++;
        else v2[x]++; 
    }
    int max1 = 0;
    int num1 = 0;
    for(auto u : v1){
        if(u.second>max1){
            max1 = u.second;
            num1 = u.first;
        }
    }
    int max2 = 0;
    int num2 = 0;
    for(auto u : v2){
        if(u.second>max2 && u.first!=num1){
            max2 = u.second;
            num2 = u.first;
        }
    }
    int ans1 = n - max1 - max2;
    max2 = 0;
    num2 = 0;
    for(auto u : v2){
        if(u.second>max2){
            max2 = u.second;
            num2 = u.first;
        }
    }
    max1 = 0;
    num1 = 0;
    for(auto u : v1){
        if(u.second>max1 && num2!=u.first){
            max1 = u.second;
            num1 = u.first;
        }
    }
    int ans2 = n - max1 - max2;
    int ans = min(ans1,ans2);
    cout<<ans<<endl;
    return 0;
}