#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(ll)n;i++)


int main(){
    string S; cin >> S;
    set<char> st;
    vector<char> v(26);
    rep(i,26){
        st.insert('a'+i);
        v[i] = 'a'+i;
    }
    rep(i,S.size()){
        st.erase(S[i]);
    }

    if(S == "zyxwvutsrqponmlkjihgfedcba"){
        cout << -1 << endl;
        return 0;
    }

    if(S.size() < 26){

        cout << S + *st.begin() << endl;
        return 0;

    }else{

        char cur = S[25], tar;
        int p;

        for(int i=1;i<26;i++){
            tar = S[25-i];

            if(cur > tar){
                p = 26-i;
                char ch = '{';
                for(int j=p;j<26;j++){
                    if(S[j] > S[p-1])ch = min(ch, S[j]);
                }
                S[p-1] = ch;
                rep(j,p){
                    cout << S[j];
                }
                cout << endl;
                return 0;
            }
            cur = tar;
        }
    }
}