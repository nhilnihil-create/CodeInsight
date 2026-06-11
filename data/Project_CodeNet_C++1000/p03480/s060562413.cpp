#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
    string S;
    cin >> S;
    int N = S.size();

    if(count(S.begin(), S.end(), '0') == N || count(S.begin(), S.end(), '0') == 0) {
        cout << N << endl;
    } else {
        int low = 1;
        int high = N;
        while(high > low+1) {
            int mid = (low + high) / 2;
            if(count(S.end()-mid, S.begin()+mid, '0') == 2*mid-N || count(S.end()-mid, S.begin()+mid, '0') == 0) {
                low = mid;
            } else {
                high = mid;
            }
        }
        cout << low << endl;
    }
    return 0;
}
