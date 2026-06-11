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
    int N;
    cin >> N;
    if(N<1200){
        cout << "ABC";
    }else if (N<2800)
    {
        cout << "ARC";
    }else{
        cout << "AGC";
    }
    

}
