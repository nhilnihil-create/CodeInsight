// C.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include<vector>
using namespace std;

int h[105];

int cnt=0;

//void f(int left, int right) {
//
//
//}
int main()
{
    int n;

    cin >> n;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    int left = 1;
    while (left <= n) {
        if (h[left] == 0) {
            left++;
            continue;
        }
        for (int i = left; i <= n; i++) {
           
            if (h[i] == 0 ) {
                cnt++;
                break;
            }
            h[i]--;
            if (i == n) {
                cnt++;
                
            }
        }


    }
    cout << cnt << endl;

    return 0;




}

