 #include <bits/stdc++.h>
#include <iostream>
#include<math.h>
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int main()
{
    vector<vector<int>>masu(3, vector<int>(3, 0));

    for (int i=0; i<3; i++) {
        int c1, c2, c3;
        cin >> c1 >> c2 >> c3;
        masu[i][0] = c1;
        masu[i][1] = c2;
        masu[i][2] = c3;
    }

    bool say_takahashi = true;
    for (int i=0; i<3; i++) {
        int add_index = i + 1;
        if (add_index == 3) {
            add_index = 0;
        }

        int one = masu[i][0] - masu[add_index][0];
        int two = masu[i][1] - masu[add_index][1];
        int three = masu[i][2] - masu[add_index][2];
        if (one != two || two != three) {
            say_takahashi = false;
            break;
        }
    }

    for (int j=0; j<3; j++) {
        int add_index = j + 1;
        if (add_index == 3) {
            add_index = 0;
        }

        int one = masu[0][j] - masu[0][add_index];
        int two = masu[1][j] - masu[1][add_index];
        int three = masu[2][j] - masu[2][add_index];
        if (one != two || two != three) {
            say_takahashi = false;
            break;
        }
    }

    if (say_takahashi) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}