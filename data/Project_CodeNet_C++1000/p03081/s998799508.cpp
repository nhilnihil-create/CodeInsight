#include <bits/stdc++.h>

using namespace std;

int check(int pos, vector< pair<char, char> > spell, string squares, int length){

    char square = squares[pos];
    //cout << endl << square;

    for (auto it : spell) {

        if (pos == length) {
            return 1;
        } else if (pos == 0) {
            return -1;
        }
        
        if (square == it.first) {
            if (it.second == 'L') {
                pos--;
                square = squares[pos];
            } else if (it.second == 'R') {
                pos++;
                square = squares[pos];
            }
        }

    }

    if (pos == length) {
        return 1;
    } else if (pos == 0) {
        return -1;
    }
    return 0;
}

int bs1(int left, int right, vector< pair<char, char> > spell, string squares, int length) {

    int ans = 0;
    while (left <= right) {

        int mid = (left + right) / 2;
        if (check(mid, spell, squares, length) == -1) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return ans;
}

int bs2(int left, int right, vector < pair<char, char> > spell, string squares, int length){

    int ans =  length;
    while (left <= right) {
        int mid = (right + left) / 2;
        if (check(mid, spell, squares, length) == 1) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return ans;
}

int main()
{
    int n, q;
    vector < pair<char, char> > spell;
    string squares;
    cin >> n >> q;
    cin >> squares;
    squares = "0" + squares + "0";
    //cout << squares;
    
    for (int i = 0; i < q; i++) {
        char t, d;
        cin >> t >> d;
        //cout << t << " " << d << endl;

        spell.push_back(make_pair(t, d));
    }

    int res1 = bs1(1, n, spell, squares, n + 1);
    int res2 = bs2(1, n, spell, squares, n + 1);
    int res = n - (res1 + n + 1 - res2);

    cout << res << endl;
    return  0;
}