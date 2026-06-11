#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

int main()
{
    string S;
    cin >> S;
    ull K;
    cin >> K;
    ull ans = 0;
    for(int i=0; i<(int)S.size(); i++){
        if(S.at(i) != '1'){
            cout << S.at(i) << endl;
            return 0;
        }
        else{
            ans += 1;
        }
        if(ans >=K){
            cout << 1 << endl;
            return 0;
        }
    }
    cout << 1 << endl;
}

