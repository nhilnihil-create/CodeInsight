#include <bits/stdc++.h>
#include <string.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define FOR(i, m, n) for(int i = m; i < n; i++) 
#define mod 1000000007
#define pi 3.1415926535
typedef long long ll;
int main(){
    int N,K;
    cin>>N>>K;
    int count=0;
    FOR(i,1,N+1){
        if(i+K-1<=N){
            count++;
        }
    }
    cout<<count<<endl;
    
    return 0;
}