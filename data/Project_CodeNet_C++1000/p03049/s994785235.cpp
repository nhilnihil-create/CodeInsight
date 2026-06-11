#include<bits/stdc++.h>
using namespace std;
 
#define rep(i, n) for (int i = 0; i < (n); i++)

int main(){
    int N;
    cin >> N;
    long long res = 0,a = 0,b = 0,c = 0;
    rep(i,N){
        string S;
        cin >> S;
        rep(i,S.length()-1){
            if(S[i] == 'A' && S[i+1] == 'B') res++;
        }
        if(S[0] == 'B' && S[S.length()-1] == 'A'){
            c++;
        }else{
            if(S[S.length()-1] == 'A') a++;
            if(S[0] == 'B') b++;
        }
    }
    if(c > 0){
        cout << res + c + ( a+b == 0 ? -1 : min(a,b))  << endl;
    }else{
        cout << res + min(a,b) << endl;
    }

    return 0;
}