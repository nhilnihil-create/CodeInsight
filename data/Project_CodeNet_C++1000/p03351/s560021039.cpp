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
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    if(abs(c-a)<=d||(abs(b-a)<=d&&abs(c-b)<=d)){
        cout << "Yes";
    }else{
        cout << "No";
    }
}
