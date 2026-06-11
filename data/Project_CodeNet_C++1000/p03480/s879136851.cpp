#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    string S;
    cin >> S;
    long T = 0;
    long min_T = (long)S.size();

    for(int i = 0; i < S.size(); i++)
    {
        if(S[i] != S[i + 1])
        {
            T = (long)max(i + 1, (int)S.size() - (i + 1));
            min_T = (long)min(T, min_T);
        }
    }

    cout << min_T << endl;
    return 0;
}
