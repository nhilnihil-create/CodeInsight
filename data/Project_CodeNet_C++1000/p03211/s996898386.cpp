#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i < (int)(n+1); i++)
const long long INF = 1LL << 60;
int main(){
     string S;
     cin>>S;
    int  ans=10000;
    for(int i=0; i<S.size()-2; i++){
        if(abs((S[i]-'0')*100+(S[i+1]-'0')*10+(S[i+2]-'0')-753)<ans){
            ans=abs((S[i]-'0')*100+(S[i+1]-'0')*10+(S[i+2]-'0')-753);
        }
    }
  cout<<ans<<endl;
}