// C.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    int min = 1000000009;
    cin >> n;

    vector<int>v(n );
    int key;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (v[i] < min) {
            min = v[i];
            key = i;
        }
    }
    int i = 0;
    while (1) {
        
        if (key != i) {
            int a = v[i] % min;
            v[i] = a;
            if (min > a && a!=0) {
                min = a;
                key = i;
                i = 0;
                continue;
            }
            
        }
        i++;
        if (i == n)break;
    }


    cout << min<<endl;
}

