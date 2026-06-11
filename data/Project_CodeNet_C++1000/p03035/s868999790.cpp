#include <bits/stdc++.h>
#define rep0(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main()
{
    int A,B;
    cin >> A >> B;
    if(A>=13){
        cout << B;
    }else if (A>5)
    {
        cout << B/2;
    }else{
        cout << 0;
    }
    
}
