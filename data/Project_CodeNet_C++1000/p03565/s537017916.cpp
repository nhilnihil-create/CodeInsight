#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long int;


int main() {
    string S, T;
    cin >> S >> T;
    int find_index = -1;
    for(int i=S.size()-T.size(); i >=0; i--) {
        bool flag = true;
        rep(j, T.size()){
            if(S[i+j]!=T[j] && S[i+j]!='?'){
                flag = false;
                break;
            }
        }
        if(flag){
            find_index = i;                
            break;
        }
    }
    if (find_index==-1) cout << "UNRESTORABLE" << endl;
    else{
        rep(i, S.size()){
            if(find_index<=i && i<find_index+(int)T.size()) cout << T[i-find_index];
            else{
                if(S[i] == '?') cout << 'a';
                else cout << S[i];
            }
        }
        cout << endl;
    }
}
