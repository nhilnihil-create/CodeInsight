#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void)
{
    string S;
    cin >> S;

    int len = S.size();
    vector<int> acgt(len, 0);

    for (int i = 0; i < len; i++)
    {
        if(S[i] == 'A' || S[i] == 'C' || S[i] == 'G' || S[i] == 'T'){
            acgt[i] = 1;
        }
    }

    int maxLen = 0;

    acgt.push_back(0);

    int cntr = 0;
    for (int i = 0; i < len + 1; i++)
    {
        if(acgt[i] == 1){
            cntr++;
        } else {
            if(maxLen < cntr) maxLen = cntr;
            cntr = 0;
        }
    }
    
    cout << maxLen << endl;

    return 0;
}
