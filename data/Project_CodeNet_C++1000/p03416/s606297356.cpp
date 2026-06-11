#include <bits/stdc++.h>

using namespace std;

int count_palindromes(int n) {
    int result = 0;
    for (int i = 1; i <= n; ++i) {
        string s = to_string(i);
        int L = s.size();
        bool is_palindrome = true;
        int j = 0;
        int k = L - 1;
        while (j < k) {
            if (s[j] != s[k]) {
                is_palindrome = false;
                break;
            }
            ++j;
            --k;
        }
        if (is_palindrome) {
            ++result;
        }
    }
    return result;
}

int main() {

    cin.tie(0);
    ios::sync_with_stdio(false);

    int A, B;
    cin >> A >> B;

    int result = count_palindromes(B) - count_palindromes(A - 1);
    cout << result << endl;

    return 0;
}
