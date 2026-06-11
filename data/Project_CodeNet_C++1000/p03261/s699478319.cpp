// A.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;
int main()
{
    int n;

    cin >> n;
    
    vector<string>W(n);
    map<string,int> m;
    for(int i = 0;i < n; i++) {

        cin >> W[i];
    }
    m[W[0]] = 1;
    for (int i = 1; i < n; i++) {
        if (W[i - 1][W[i - 1].size() - 1] != W[i][0]) {
            cout << "No" << endl;
            return 0;
        }
        else if (m.count(W[i]) != 0) {
            cout << "No" << endl;
            return 0;
        }

        m[W[i]] = 1;


    }
    cout << "Yes" << endl;

    return 0;
}

