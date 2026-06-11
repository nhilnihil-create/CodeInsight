#include<bits/stdc++.h>
using namespace std;
//KASRA FOULADI;
int main(){
    bool b = true;
    int n, m;
    cin >> n >> m;
    char s[52][52];
    for(int i = 0; i < n; ++i)
        cin >> s[i];
    for(int i = 0; i < n && b; ++i)
        for(int j = 0; j < m && b; ++j)
            if(s[i][j] == '#')
                b = (i && s[i - 1][j] == '#') || (j && s[i][j - 1] == '#') || (i != n - 1 && s[i + 1][j] == '#') || (j != m - 1 && s[i][j + 1] == '#');
    if(b)
        cout << "Yes" << '\n';
    else
        cout << "No" << '\n';
}