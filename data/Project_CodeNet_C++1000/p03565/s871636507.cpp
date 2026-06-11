#include<bits/stdc++.h>
#define INF 1e7

using namespace std;
typedef long long int ll;


int main()
{
    string S,T; cin >> S >> T;
    if(S.length() < T.length())
    {
        cout << "UNRESTORABLE" << endl;
        return 0;
    }
    int p = -1;
    for(int i = 0; i <= S.length() - T.length(); i++)
    {
        if(S[i] == T[0] || S[i] == '?')
        {
            bool f = true;
            for(int j = 0; j < T.length(); j++) 
            {
                if(S[i+j] == '?') continue;
                if(S[i+j] == T[j]) continue;
                f = false;
            }
            if(f) p = i;
        }
    }
    if(p == -1) 
    {
        cout << "UNRESTORABLE" << endl;
        return 0;
    }
    for(int i = 0; i < T.length(); i++) S[i+p] = T[i];
    for(int i = 0; i < S.length(); i++) if(S[i] == '?') S[i] = 'a';
    cout << S << endl;
}