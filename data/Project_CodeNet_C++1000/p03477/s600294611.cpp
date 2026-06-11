#include <bits/stdc++.h>    //C++の標準ライブラリのヘッダを全て読み込む
 
int main() {
    using std::cout;
    using std::endl;
    using std::cin;
    using std::string;

    int l, r;
    int a,b,c,d;
    cin >> a >> b >> c >> d;


    if (a+b == c+d) {
        cout << "Balanced" << endl;
    } else if(a+b < c+d) {
        cout << "Right" << endl;
    } else {
        cout << "Left" << endl;
    }

}