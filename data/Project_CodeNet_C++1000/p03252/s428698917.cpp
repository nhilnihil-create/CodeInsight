#include<bits/stdc++.h>
using namespace std;

int main(){
    string S,T;
    cin >> S >> T;
    vector<int>S2(26);
    vector<int>T2(26);
    for(int i = 0; i < S.size(); i++) {
        S2[S[i]-'a']++;
        T2[T[i]-'a']++;
    }
    sort(S2.begin(),S2.end());
    sort(T2.begin(),T2.end());
    for(int i = 0; i < 26; i++) {
        if(S2[i] != T2[i]) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}
