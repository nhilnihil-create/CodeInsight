#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define fst first
#define snd second

int main()
{
    string s;
    cin >> s;

    vector<int> cnt(35);
    for(int i = 0; i < s.size(); i++)
        cnt[s[i] - 97]++;

    if(cnt[0] && cnt[1] && cnt[2])
        cout << "Yes";
    else
        cout << "No";

    return 0;
}
