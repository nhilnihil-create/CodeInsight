#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    string S;
    cin >> S;
    int len = S.size();
    int keylen = 7;

    bool clear = false;
    for(int i = 0; i < keylen; i++){
        string t = S.substr(0,i) + S.substr(len - (keylen - i));
        if(t == "keyence"){
            clear = true;
            break;
        }
    }

    if(clear){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
