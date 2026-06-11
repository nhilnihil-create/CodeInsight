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
    string input;
    cin >> input;
    int res = 0;
    rep0(i,3){
        if(input[i]=='o'){
            res++;
        }
    }
    cout << 700+res*100 << endl;
}
