#include<bits/stdc++.h>
using namespace std;
int main(){
    string S;
    cin >> S;
    int ans = 0;
    for(int i = 0; i < S.size(); i++){
        if(S.at(i) == 'o'){
            ans++;
        }
    }
    cout << 700 + 100 * ans << endl;
    return 0;
}