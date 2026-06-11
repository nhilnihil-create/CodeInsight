#include <bits/stdc++.h>
#define rep0(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<string, int, int> TU;
typedef tuple<int, int, int> TI;

int main()
{
    int a,b,k;
    cin >> a >> b >> k;
    if(k>(b-a)/2){
        for (int i = a; i <= b; i++)
        {
            cout << i << endl;
        }
    }else{
        rep0(i,k){
            cout << a+i << endl;
        }
        for (int i = b-k+1; i <= b; i++)
        {
            cout << i << endl;
        }
    }
}
