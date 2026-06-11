// ＡＢＣのＡ過去問を解くだけだよ

// フォント:Electroharmonix
// x:小文字(ｘ)    X:大文字(Ｘ)
// +:プラス(＋)    &:アンド(＆)

#include <bits/stdc++.h>

using namespace std;

void Main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (abs(a - c) <= d 
        || (abs(a - b) <= d && abs(b - c) <= d))
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
    
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    //std::cout << std::fixed << std::setprecision(10);

    /*
	while (true)
	{
		Main();
		cout << endl;
	}
	//*/

    Main();
    cout << endl;

    return 0;
}