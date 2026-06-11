#include <bits/stdc++.h>
using namespace std;
#define lint long long
#define P pair<int, int>

int main(){
    string S;
    
    cin >> S;
    

    int len = S.length();
    int num = len;
    for(int i = 0; i < len - 1; ++i){
        if(S[i] != S[i + 1]){
            num = min(num, max(i + 1, len - i - 1));
        }
    }
    
    cout << num << endl;
}
