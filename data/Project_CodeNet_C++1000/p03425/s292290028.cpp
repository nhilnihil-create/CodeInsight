#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<string> s(n);
    for(int i = 0; i < n; i++) cin >> s[i];

    vector<int> count(5, 0);
    for(int i = 0; i < n; i++){
        if(s[i][0] == 'M') count[0]++;
        else if(s[i][0] == 'A') count[1]++;
        else if(s[i][0] == 'R') count[2]++;
        else if(s[i][0] == 'C') count[3]++;
        else if(s[i][0] == 'H') count[4]++;
    }

    long long int ans = 0;
    for(int bit = 0; bit < (1 << 5); bit++){
        long long int coans = 1;
        int num = 0;
        for(int i = 0; i < 5; i++){
            if(bit & (1 << i)){
                coans *= count[i];
                num++;
            }
        }
        if(num == 3) ans += coans;
    }
    cout << ans << endl;
    return 0;
}