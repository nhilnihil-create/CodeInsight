#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, aCnt = 0, bCnt = 0;
    cin >> n;
    int cards[n];
    for(int i = 0; i < n; i++)
        cin >> cards[i];
    sort(cards, cards + n, greater<int>());
    for(int i = 0; i < n; i++){
        if((i + 1) % 2 != 0)
            aCnt += cards[i];
        else
            bCnt += cards[i];
    }
    cout << aCnt - bCnt << "\n";
    return 0;
}
