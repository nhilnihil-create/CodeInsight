#include <iostream>
using namespace std;

string S; int N;
void input()
{
    cin >> S;
    N = S.length();
}

void solve()
{
    int zero = 0, one = 0;
    for(int i=0; i<N; ++i){
        if(S[i] == '0') ++zero;
        else if(S[i] == '1') ++one;
    }
    cout << 2*min(zero,one) << endl;
}

int main()
{
    cin.tie();
    ios::sync_with_stdio(false);
    input();
    solve();
    return 0;
}