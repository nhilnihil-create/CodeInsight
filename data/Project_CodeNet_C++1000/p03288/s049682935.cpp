// ＡＢＣのＡ過去問を解くだけだよ

// フォント:Electroharmonix
// x:小文字(ｘ)    X:大文字(Ｘ)
// +:プラス(＋)    &:アンド(＆)

#include <bits/stdc++.h>

using namespace std;

void Main()
{
    int R;
    cin >> R;

    if (R < 1200)
        cout << "ABC";
    else if (R < 2800)
        cout << "ARC";
    else
        cout << "AGC";
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    //std::cout << std::fixed << std::setprecision(10);

#ifdef DEBUG_BUILD
    while (true)
    {
        Main();
        cout << std::endl;
    }
#endif

    Main();
    cout << endl;

    return 0;
}