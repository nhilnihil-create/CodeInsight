#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    string S;
    cin >> S;
    /*
    int black_pos = 0;
    for(size_t i = 0; i < S.size(); i++){
        if(S[i] == 'B') black_pos += i;
    }
    sort(S.rbegin(), S.rend());
    int new_black_pos = 0;
    for(size_t i = 0; i < S.size(); i++){
        if(S[i] == 'B') new_black_pos += i;
    }
    cout << new_black_pos - black_pos << endl;
    */
    long long white_num = 0;
    long long count = 0;
    for(int i = 0; i < (int)S.size(); i++){
        if(S[i] == 'W'){
            count += i - white_num;
            white_num++;
        }
    }
    cout << count << endl;

}