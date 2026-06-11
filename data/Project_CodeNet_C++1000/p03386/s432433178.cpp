#include <bits/stdc++.h>
#include <string.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define FOR(i, m, n) for(int i = m; i < n; i++) 
#define mod 1000000007
#define pi 3.1415926535
typedef long long ll;
typedef vector<int> ve;
int main(){
    int A,B,K;
    cin>>A>>B>>K;
    set<int>s;
    FOR(i,A,A+K){
        s.insert(i);
    }
    for(int i=B;i>B-K;i--){
        s.insert(i);
    }
    for(auto x:s){
        if(x>=A&&x<=B){
            cout<<x<<endl;
        }
    }
    return 0;
}