#include <bits/stdc++.h>

using namespace std;

int main(){
    string S;
    int N;
    cin >> N;

    int Bsum[N],Wsum[N],W=0,B=0,ans=1e9;

    cin >> S;

    for(int i=0;i<N;i++){
        if(S[i]=='#'){
            B++;
        }else{
            W++;
        }
        Bsum[i] = B;
        Wsum[i] = W;
    }


    for(int i=0;i<N;i++){
        if(i==0){
            ans = min(ans,W-Wsum[i]);
        }else{
            ans = min(ans,Bsum[i-1]+W-Wsum[i]);
        }
    }

    if(B==0 || W==0){
        cout << 0 << endl;
    }else{
        cout << ans << endl;
    }
}