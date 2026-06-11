//  ©   ___MRX___

#include <bits/stdc++.h>
    using namespace std;

#define ll long long int

int main()
{
    int i, n, x, flag = 1, ans = 0, count;
    string s;
    vector<int> checker1(26);
    vector<int> checker2(26);

    cin >> n >> s;
    x = n;

    while(x > 1) {
        for(i = 0; i < 26; i++) {
            checker1[i] = 0;
            checker2[i] = 0;
        }
        count = 0;

        for(i = 0; i < flag; i++) {
            if(checker1[s[i] - 'a'] == 0) {
                checker1[s[i] - 'a'] = 1;
            }
        }
        for(i = flag; i < n; i++) {
            if(checker2[s[i] - 'a'] == 0) {
                checker2[s[i] - 'a'] = 1;
            }
        }

        for(i = 0; i < 26; i++) {
            if(checker1[i] && checker2[i])
                count++;
        }

        flag++;
        x--;
        ans = max(ans, count);
    }

    cout << ans << '\n';

    return 0;
}
