#include<bits/stdc++.h>

using namespace std;

int main(){
    int N,Q;
    string S;
    cin >> N >> Q >> S;

    vector<bool> isAC(N, false);
    for(int i=0; i<N-1; i++){
        if(S.at(i) == 'A' && S.at(i+1) == 'C')isAC.at(i) = true;
    }

    // cout << "isAC:" << endl;
    // for(bool b : isAC)cout << ((b) ? 1 : 0) << " ";
    // cout << endl;

    vector<int> cs(N+1, 0);
    for(int i=0; i<N; i++)cs.at(i+1) = cs.at(i) + ((isAC.at(i)) ? 1 : 0);

    // cout << "cs: " << endl;
    // for(int i : cs)cout << i << " ";
    // cout << endl;

    for(int i=0; i<Q; i++){
        int l,r;
        cin >> l >> r;
        l--; r--;
        cout << cs.at(r) - cs.at(l) << endl;
    }
}