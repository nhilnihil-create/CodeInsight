#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(void){
    
    int n, q;
    cin >> n >> q;
    
    string s;
    cin >> s;
    
    vector<int> numberOfAC(n+1);
    
    for (int i = 1; i < n; i++){
        numberOfAC[i] = numberOfAC[i-1];
        if (s[i-1] == 'A' && s[i] == 'C') numberOfAC[i]++;
    }
    
    for (int i = 0; i < q; i++){
        int l, r;
        cin >> l >> r;
        l--,r--;
        cout << numberOfAC[r] - numberOfAC[l] << endl;
    }
    return 0;
}
