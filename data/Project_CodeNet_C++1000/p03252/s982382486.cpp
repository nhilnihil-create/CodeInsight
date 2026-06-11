#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

string S,T;
void input()
{
    cin >> S >> T;
}

void solve()
{
    bool ans = true;
    char P[26][1];
    for(int i=0; i<26; ++i){
        P[i][0] = '0';
    }
    for(int i=0; i<S.length(); ++i){
        if(P[S[i]-'a'][0] != '0'){
            if(P[S[i]-'a'][0] == T[i]) continue;
            ans = false; break;
        }
        P[S[i]-'a'][0] = T[i]; 
    }

    for(int i=0; i<26; ++i){
        P[i][0] = '0';
    }
    for(int i=0; i<S.length(); ++i){
        if(P[T[i]-'a'][0] != '0'){
            if(P[T[i]-'a'][0] == S[i]) continue;
            ans = false; break;
        }
        P[T[i]-'a'][0] = S[i]; 
    }

    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main()
{
    cin.tie();
    ios::sync_with_stdio(false);
    input();
    solve();
    return 0;
}