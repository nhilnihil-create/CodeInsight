#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<char> s(n);
    for(int i = 0; i < n; i++) cin >> s[i];

    vector<bool> isexist(4, false);
    for(int i = 0; i < n; i++){
        if(s[i] == 'P') isexist[0] = true;
        else if(s[i] == 'W') isexist[1] = true;
        else if(s[i] == 'G') isexist[2] = true;
        else isexist[3] = true;
    }
    int ans = 0;
    for(int i = 0; i < 4; i++){
        if(isexist[i]) ans++;
    }
    if(ans == 3) cout << "Three" << endl;
    else cout << "Four" << endl;
    return 0;
}