#include <bits/stdc++.h>
using namespace std;
#define PI 3.141592653589793
#define MOD 1000000007
typedef long long ll;
typedef long double ld;

int main() {
    string str,S;
    cin >> str >> S;
    ll tmp = -1;

    if(str.size() < S.size()){
        cout << "UNRESTORABLE" << endl;
        return 0;        
    }

    for(int i = 0; i <= ll(str.size()) - ll(S.size()); i++){
        bool flag = true;
        for(int j = 0; j < ll(S.size()); j++){
            if(str[i + j] == '?' || str[i + j] == S[j] ){
            }
            else{
                flag = false;
            }
        }
        if(flag){
            tmp = i;
        }
    }
    if(tmp == -1){
        cout << "UNRESTORABLE" << endl;
        return 0;
    }
    else{
        for(int i = tmp; i < tmp + ll(S.size()); i++){
            str[i] = S[i - tmp];
        }
        for(int i = 0; i < ll(str.size()); i++){
            if(str[i] == '?'){
                str[i] = 'a';
            }
        }
    }
    cout << str << endl;
}
