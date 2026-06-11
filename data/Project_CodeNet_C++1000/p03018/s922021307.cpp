#include <vector>
#include <string>
#include <iostream>
#include <queue>
#include <algorithm>
#include <functional>
#include <map>
#include <array>
#include <cmath>

using namespace std;

long long PRIME = 1000000007;


int main(int argc, char* argv[]){
    string S;
    cin >> S;

    int count_A = 0;
    long long ret = 0;

    int cursor = 0;

    while(cursor < S.size() - 1){
        if(S[cursor] == 'A'){
            ++count_A;
            ++cursor;
        }
        else if(S[cursor] == 'B' && S[cursor+1] == 'C'){
            ret += count_A;
            cursor += 2;
        }
        else{
            count_A = 0;
            ++cursor;
        }
    }

    cout << ret;

}
