#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
#include <bitset>

using namespace std;

int main(){
    string S;
    cin >> S;

    int len = 0;
    int cnt = 0;
    int max_len = 0;
    
    for(int i=0; i<=S.length(); i++){
        if( S[i] == 'A' || 
            S[i] == 'C' ||
            S[i] == 'G' ||
            S[i] == 'T'
        ){
            /* カウント */
            cnt++;
            max_len = max(cnt, max_len);
        }
        else{
            cnt = 0;
        }
    }

    cout << max_len << endl;
}