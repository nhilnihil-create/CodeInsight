#include <iostream>
#include <string>
using namespace std;

int main() {
    string S;
    string subs;
    bool flag;
    size_t max_size=0;
    cin >> S;
    for (size_t i = 0; i < S.size(); i++)
    {
        for (size_t j = 1; j < S.size() - i + 1; j++)
        {
            subs = S.substr(i, j);
            flag = true;
            for (size_t k = 0; k < subs.size(); k++)
            {
                // ACGT以外の文字が一つでもあったら
                if ((subs[k] != 'A') && (subs[k] != 'C') && (subs[k] != 'G') && (subs[k] != 'T')) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                if (max_size < subs.size()) max_size = subs.size();
            }
            
        }    
    }
    
    cout << max_size << endl;
    return 0;
}