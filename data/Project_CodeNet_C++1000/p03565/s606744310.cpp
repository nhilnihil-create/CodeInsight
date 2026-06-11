#include<bits/stdc++.h>
using namespace std;

int N, M;
string S, T;

int main()
{
    cin >> S >> T;
    N = S.length();
    M = T.length();

    for(int i = N - M; i >= 0; i--)
    {
        for(int j = 0; j <= M; j++)
        {
            if(j == M)
            {
                replace(S.begin(), S.end(), '?', 'a');
                for(int k = 0; k < M; k++) S[i + k] = T[k];
                cout << S << endl;
                return 0;
            }
            if(S[i + j] == '?' || S[i + j] == T[j]);
            else break;
        }
    }

    cout << "UNRESTORABLE" << endl;

    return 0;
}