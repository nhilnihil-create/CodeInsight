#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;

int main(){
    string S;
    long long K;
    cin >> S;
    cin >> K;

    int one_max_index = -1;
    char next_char;
    for(int i=0; i<S.size(); i++){
        char c = S[i];
        if(c!='1'){
            next_char = S[i];
            break;
        }
        one_max_index += 1;
    }

    if(K-1 <= one_max_index){
        cout << '1' << endl;
    }else{
        cout << next_char << endl;
    }

    return 0;
}