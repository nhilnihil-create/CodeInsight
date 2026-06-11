#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pii pair<int , int>
#define _FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAXX1005

bool f(int a){
    if(a >= 1 && a <= 12)
        return true;
    return false;
}

int n , k;
string s;

int main()
{
    _FastIO;
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        n *= 10;
        n += (int(s[i]) - 48);
    }
    int x = n / 100;
    int y = n % 100;
    bool r = f(x);
    bool t = f(y);
    if(r && t){
        cout << "AMBIGUOUS" << endl;
        return 0;
    }
    if(!r && !t){
        cout << "NA" << endl;
        return 0;
    }
    if(r)
        cout << "MMYY" << endl;
    else
        cout << "YYMM" << endl;
    return 0;
}
