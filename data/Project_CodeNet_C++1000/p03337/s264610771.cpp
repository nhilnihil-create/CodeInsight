// ＡＢＣのＡ過去問を解くだけだよ

// フォント:Electroharmonix
// x:小文字(ｘ)    X:大文字(Ｘ)
// +:プラス(＋)    &:アンド(＆)

#include <bits/stdc++.h>

using namespace std;

void Main()
{
    int a, b;
    cin >> a >> b;

    cout << max({a + b, a - b, a * b});
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