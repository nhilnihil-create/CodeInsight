#include<bits/stdc++.h>
using namespace std;
 
#define rep(i, n) for (int i = 0; i < (n); i++)


int main(){
    string S;
    cin >> S;
    int l = 0,r= S.length()-1;
    int res = 0;
    while(l < r){
        if(S[l] == S[r]){
            l++;
            r--;
        }else if(S[l] == 'x'){
            res++;
            l++;
        }else if(S[r] == 'x'){
            res++;
            r--;
        }else{
            res = -1;
            break;
        }
    }
    cout << res << endl;
    return 0;
}