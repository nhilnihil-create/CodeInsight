#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;

int main(){
    string S;
    cin >> S;

    if(S[0] != 'A'){
        cout << "WA" << endl;
        return 0;
    }

    int count_large_C = 0;
    int target_i = 0;
    for(int i=2; i<S.size()-1; i++){
        if(S[i] == 'C'){
            count_large_C += 1;
            target_i = i;
        }
    }
    if(count_large_C != 1){
        cout << "WA" << endl;
        return 0;
    }

    for(int i=1; i<S.size(); i++){
        if(i==target_i){continue;}

        if(S[i] >= 'a' && S[i] <= 'z'){
            continue;
        }else{
            cout << "WA" << endl;
            return 0;
        }
    }

    cout << "AC" << endl;
    return 0;
}