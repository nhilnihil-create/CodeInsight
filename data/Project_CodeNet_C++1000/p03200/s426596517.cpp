#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(void){
    string S;
    cin >> S;

    ll sum = 0;
    ll app = 0;
    int length = S.size();

    for(int i = 0; i < length; i++){
        if(S[i] == 'W'){
            sum += (i - app);
            app++;
        }
    }

    cout << sum << endl;

    return 0;
}
