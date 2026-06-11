#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    int N;
    char ch;
    int p = 0;
    int w = 0;
    int g = 0;
    int y = 0;

    cin >> N;

    rep(i, N)
    {
        cin >> ch;
        switch(ch){
            case 'P':
                p = 1;
                break;
            case 'W':
                w = 1;
                break;
            case 'G':
                g = 1;
                break;
            case 'Y':
                y = 1;
                break;
        }
    }

    if ((p + w + g + y) == 3){
        cout << "Three" << endl;
    }else{
        cout << "Four" << endl;
    }

    return 0;
}