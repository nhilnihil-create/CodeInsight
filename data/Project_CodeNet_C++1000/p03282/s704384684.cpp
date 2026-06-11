////////////////////////////////////
///     Please Give Me AC!!!     ///
////////////////////////////////////

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define forin(in) for(int i=0; i<(int)in.size(); i++) cin>>in[i]
#define forout(out) for(int i=0; i<(int)out.size(); i++) cout<<out[i]<<endl
#define rep(i, n) for(int i=0; i<(n); i++)

int main(){
    string S; cin>> S;
    ll K; cin>> K;

    int idx;
    rep(i, S.size()){
        if(S[i] != '1'){
            idx = i;
            break;
        }
    }

    if(idx < K){
        cout<< S[idx] << endl;
    }else{
        cout<< 1 << endl;
    }
}