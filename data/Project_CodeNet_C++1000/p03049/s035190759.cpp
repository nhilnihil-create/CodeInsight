#include <bits/stdc++.h>

using namespace std;

int main(){
    int N,A=0,B=0,C=0,ans=0;
    cin >> N;

    for(int i=0;i<N;i++){
        string S;
        cin >> S;

        if(S[0]=='B'){
            if(S.back()=='A'){
                C++;
            }else{
                B++;
            }
        }else{
            if(S.back()=='A'){
                A++;
            }
        }

        for(int i=1;i<S.size();i++){
            if(S[i]=='B' && S[i-1]=='A'){
                ans++;
                i++;
            }
        }
    }

    if(C==0){
        cout << ans + min(A,B) << endl;
    }else if(A==B && A==0){
        cout << ans + C - 1 << endl;
    }else{
        cout << ans + C + min(A,B) << endl;
    }
}