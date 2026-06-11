// C.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{

    int cx, cy,ansh;

    int n;
    cin >> n;

    int data[100][3];
    for (int i = 0; i < n; i++) {
        cin >> data[i][0] >> data[i][1] >> data[i][2];
    }
    bool ok ;
    for (int x = 0; x <= 100; x++) {
        for (int y = 0; y <= 100; y++) {
            int h;
            ok = true;
            for (int i = 0; i < n; i++) {
                if (data[i][2] > 0) {
                    h = data[i][2] + abs(data[i][0] - x) + abs(data[i][1] - y);
                    break;
                }
            }
         //   cout << h << endl;
            for (int i = 0; i < n; i++) {
                if (max(h - abs(data[i][0] - x) - abs(data[i][1] - y), 0) != data[i][2]) {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                cx = x;
                cy = y;
                ansh = h;
                break;
            }


        }
        if (ok) {
            break;
        }
    }

    cout << cx << " " << cy << " " << ansh << endl;


    return 0;
    
}

