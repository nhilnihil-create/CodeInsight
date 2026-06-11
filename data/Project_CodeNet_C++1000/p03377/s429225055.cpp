// ＡＢＣのＡ過去問を解くだけだよ
// フォント    x:小文字(ｘ)    X:大文字(Ｘ)

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, x;
    cin >> a >> b >> x;

    x -= a;

    if (0 <= x && x <= b)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
