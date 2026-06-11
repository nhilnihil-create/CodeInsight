#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    string S;
    cin>>S;
    int K;
    cin>>K;
    bool ans=false;
    rep(i,S.size()){
        if(S[i]=='1'&&K!=i+1){
        }
      else{
            cout<<S[i]<<endl;
            ans=true;
            break;
        }
    }
    if(ans==false){
        cout<<1<<endl;
    }
}

