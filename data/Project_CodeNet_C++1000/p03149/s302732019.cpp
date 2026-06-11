#include<iostream>
#include<vector>
#include<array>
#include<algorithm>

#define rep(i, n) for(int i = 0; i < n; i++)

using namespace std;

int main()
{
    int n[4];

    rep(i, 4) cin >> n[i];

    int ch[4] = {0};
    rep(i, 4){
        switch(n[i]){
            case 1 : ch[0] = true; break;
            case 9 : ch[1] = true; break;
            case 7 : ch[2] = true; break;
            case 4 : ch[3] = true; break;
        }
    }
    if(ch[0] == true && ch[1] == true && ch[2] == true && ch[3] == true)
        cout << "YES";
    else
        cout << "NO";

    cout << endl;
}