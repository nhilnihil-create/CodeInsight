#include <iostream>
using namespace std;

int main() {

    string S;
    int max = 0;
    int tmp_max = 0;

    cin >> S;

    bool flg = false;

    for (int i = 0; i < S.size(); i++) {
        char c = S[i];
        //cout << c << endl;
        if (c == 'A' || c == 'G' || c == 'C' || c == 'T'){
            flg = true;
        }else{
            flg = false;
        }

        if (flg){
            tmp_max++;
        }else{
            if(max < tmp_max){
                max = tmp_max;
            }
            tmp_max = 0;
        }
    }
    if (flg){
        if(max < tmp_max){
            max = tmp_max;
        }
    }

    cout << max << endl;

    
    return 0;

}