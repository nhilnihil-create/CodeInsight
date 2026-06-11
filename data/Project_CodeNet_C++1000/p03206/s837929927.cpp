#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
const long long INF = numeric_limits<long long>::max();
typedef long long ll;
int main(void)
{
    int D;
    cin >> D;
    switch(D){
        case 25:
            cout << "Christmas" << endl;
            break;
        case 24:
            cout << "Christmas Eve" << endl;
            break;
        case 23:
            cout << "Christmas Eve Eve" << endl;
            break;
        case 22:
            cout << "Christmas Eve Eve Eve" << endl;
    }
    return 0;
}