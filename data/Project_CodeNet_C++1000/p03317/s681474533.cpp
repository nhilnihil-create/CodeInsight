// C.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include<vector>
using namespace std;
int main()
{
    int n,k;

    cin >> n>>k;

    vector<int>a(n);
    int key;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 1) { key = i; }
    }

    int x = key;
    int y = n - 1 - key;
    int sum = 0;
    if (x >= k - 1) {
       // sum += (x + k-2) / (k-1);
        sum += x / (k - 1);
        if (x % (k - 1) == 0) {
          
        }
        else {
            sum++;
        }
       // sum += (y + k-2) / (k-1);
        sum += y / (k - 1);
        if (y % (k - 1) == 0) {

        }
        else {
            sum++;
        }
    }
    else {
        sum++;
        y -= (k - 1 - x);
        sum += y / (k - 1);
        //sum += (y + k - 2) / (k - 1);
        if (y % (k - 1) == 0) {

        }
        else {
            sum++;
        }
    }

    //cout << sum << endl;
    int ans = 0;
    if ((n - 1) % (k - 1) == 0) {
        ans = (n - 1) / (k - 1);
    }
    else {
        ans = (n - 1) / (k - 1) + 1;
    }

    cout << ans << endl;

    return 0;
    


}

