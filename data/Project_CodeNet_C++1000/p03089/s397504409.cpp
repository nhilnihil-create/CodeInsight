#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void)
{
    int n;
    cin >> n;
    vector<int> b(n);
    vector<int> modIndex(n);
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        modIndex[i] = i+1;
    }

    vector<int> outBuf;
    for(int i = n; i >= 0; i--){
        if(modIndex[i] > 0){
            if(modIndex[i] == b[i]){
                outBuf.push_back(b[i]);
                modIndex[i] = -1;

                for (int j = i+1; j < n; j++)
                {
                    modIndex[j]--;
                }

                i = n;
            }
        }
    }

    if((int)outBuf.size() == n){
        for (int i = n-1; i >= 0; i--)
        {
            cout << outBuf[i] << endl;
        }
        
    } else {
        cout << -1 << endl;
    }

    return 0;
}
