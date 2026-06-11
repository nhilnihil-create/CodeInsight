#include <bits/stdc++.h>
using namespace std;

int count_div(int num) {
    map<int, int> divs{
        {3, 0},
        {5, 0},
        {7, 0},
        {11, 0},
        {13, 0}
    };
    int keys[] = {3, 5, 7, 11, 13};

    for (int i = 0; i < 5; i++) {
        while(num%keys[i] == 0) {
            divs[keys[i]]++;
            num /= keys[i];
        }
    }

    return (divs[3]+1)*(divs[5]+1)*(divs[7]+1)*(divs[11]+1)*(divs[13]+1);
}

int main() {
    int N;
    cin >>N;
    int ret = 0;

    for (int i = 1; i <= N; i++) {
        if (i%2==1) {
            int t = count_div(i);
            if (t == 8) ret++;
        }
    }
    cout << ret << endl;
    return 0;
}