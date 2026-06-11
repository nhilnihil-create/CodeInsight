#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    int n;

    cin >> n;

    vector<int> white(n, 0);
    vector<int> black(n, 0);

    for(int i = 0; i < n; ++i) {
        char ch;
        cin >> ch;

        if(ch == '.')
            white[i]++;
        else
            black[i]++;
        
        if(i) {
            white[i] += white[i - 1];
            black[i] += black[i - 1];
        }
    }


    if(white[n - 1] == n || black[n - 1] == n) {
        cout << 0 << endl;
        return 0;
    }

    int ans = 999999999;

    for(int i = 0; i <= n; ++i) {

        int leftBlack;
        int leftWhite;
        if(i) {
            leftBlack = black[i - 1];
            leftWhite = white[i - 1];
        }
        else {
            leftBlack = leftWhite = 0;
        }

        int rightWhite;
        if(i < n) 
            rightWhite = white[n - 1] - leftWhite;
        else
            rightWhite = 0;

        ans = min(ans, leftBlack + rightWhite);

    }

    cout << ans << endl;

    return 0;
}