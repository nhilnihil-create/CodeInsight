#include <bits/stdc++.h>
#define rep0(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<string, int, int> TU;

int main()
{
    int a,b,c;
    cin >> a >> b >> c;
    if(b/a<c){
        cout << b/a;
    }else{
        cout << c;
    }
}
