#include <bits/stdc++.h>
#include <string.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define FOR(i, m, n) for(int i = m; i < n; i++) 
#define mod 1000000007
#define pi 3.1415926535
typedef long long ll;
int main(){
    vector<int>N(4);
    vector<int>A={1,4,7,9};
    rep(i,4){
        cin>>N[i];
    }
    sort(N.begin(),N.end());
    if(N==A){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    return 0;
}