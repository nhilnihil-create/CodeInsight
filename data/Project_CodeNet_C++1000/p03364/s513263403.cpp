#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    char s[303][303];
    int ans = 0;
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> s[i][j];
    for(int l = 0; l < n; l++){
        bool yes = true;
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) if(s[(i + l) % n][j] != s[(j + l) % n][i]) yes = false;
        if(yes) ans += n;
    }
    cout << ans << endl;
}