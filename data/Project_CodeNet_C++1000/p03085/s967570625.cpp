#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pii pair<int , int>
#define _FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAXX 1005

char c;
char b[5] = {'A' , 'C' , 'G' , 'T'};

int main()
{
    _FastIO;
    cin >> c;
    if(c == 'A'){
        cout << 'T' << endl;
        return 0;
    }
    if(c == 'C'){
        cout << 'G' << endl;
        return 0;
    }
    if(c == 'G'){
        cout << 'C' << endl;
        return 0;
    }
    cout << 'A' << endl;
    return 0;
}
