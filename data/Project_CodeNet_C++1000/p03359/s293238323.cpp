// ＡＢＣのＡ過去問を解くだけだよ
// フォント    x:小文字(ｘ)    X:大文字(Ｘ)
//                  +:プラス(＋)   &:アンド(＆)

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    int ret = a - 1;

    if (a <= b)
        ret++;

    cout << ret;

    return 0;
}
