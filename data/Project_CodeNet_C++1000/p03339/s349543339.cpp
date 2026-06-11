#include <bits/stdc++.h>

using namespace std;

int
main(void)
{
    int N;
    string S;
    int left_w = 0, right_e = 0;
    int result = numeric_limits<int>::max();

    cin >> N;
    cin >> S;

    for(char c : S) {
        if(c == 'E') right_e++; 
    }

    for(char c : S) {
        if(c == 'E') right_e--;
        result = min(result, left_w + right_e);
        if(c == 'W') left_w++;
    }
    cout << result << endl;

}
