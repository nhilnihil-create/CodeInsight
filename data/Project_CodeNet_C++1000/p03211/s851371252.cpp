#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
#define ll long long

void solve_B(){
    string s;
    cin >> s;

    int n = s.size();
    int ans = 10000;
    for(int i = 0; i < n-2; i++){
        int x = 100 * (s[i] - '0') + 10 * (s[i+1] - '0') + (s[i+2] - '0');
        int sa = fabs(x - 753);
        ans = min(ans, sa);
    }

    cout << ans << endl;
}

int main(void){
    solve_B();
    return 0;
}