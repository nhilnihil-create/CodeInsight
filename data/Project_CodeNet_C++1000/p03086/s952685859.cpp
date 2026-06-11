#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.14159265359
#define rep(i,n) for(int i=0;i<(n);i++)
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int main()
{
    string s, ans, hoge;
    cin >> s;
    for (int i = 0; i < s.size(); i++){
        for (int j = 0; j < s.size() - i + 1;j++){
            hoge = s.substr(i, j);
            bool ok = true;
            for (int k = 0; k < hoge.size(); k++)
            {
                if(!(hoge[k] =='A'|| hoge[k] == 'C' || hoge[k] == 'G' || hoge[k]== 'T'))
                    ok = false;
            }
            if(ok && hoge.size() > ans.size())
                ans = hoge;
        }
    }
    cout << ans.size() << endl;
    return 0;
}