#include <iostream>
#include <string>
using namespace std;

int main(){
    int n;
    cin >> n;
    int count[5] = {};
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        switch(s[0]){
            case 'M': count[0]++; break;
            case 'A': count[1]++; break;
            case 'R': count[2]++; break;
            case 'C': count[3]++; break;
            case 'H': count[4]++; break;
            default: break;
        }
    }

    long long int ans = 0;
    int p[] = {0, 0, 0, 0, 0, 0, 1, 1, 1, 2};
    int q[] = {1, 1, 1, 2, 2, 3, 2, 2, 3, 3};
    int r[] = {2, 3, 4, 3, 4, 4, 3, 4, 4, 4};
    for(int i = 0; i < 10; i++){
        long long int coans = count[p[i]];
        coans *= count[q[i]];
        coans *= count[r[i]];
        ans += coans;
    }
    cout << ans << endl;
    return 0;
}