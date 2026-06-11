#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    for(int i = 1; i < n; i++){
        vector<int> x(26, 0), y(26, 0);
        for(int j = 0; j < i; j++){
            x[s[j]-'a'] = 1;
        }
        for(int j = i; j < n; j++){
            y[s[j]-'a'] = 1;
        }
        int coans = 0;
        for(int j = 0; j < 26; j++){
            if(x[j] == 1 && y[j] == 1) coans++;
        }
        if(ans < coans) ans = coans;
    }
    cout << ans << endl;
    return 0;
}