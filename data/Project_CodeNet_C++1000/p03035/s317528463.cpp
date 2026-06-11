#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>

using namespace std;
const double PI = (acos(-1));
const long long MOD = pow(10, 9) + 7;
long long kaizyou(int N);
long long POW(int J);

bool judge(int dt, int dx, int dy);

int main()
{
    int A,B;
    cin >> A >> B;
    
    if(A >= 13)
    {
        cout << B;
    }else if(A >= 6 && 12 >= A)
    {
        cout << B/2;
    }else
    {
        cout << 0;
    }
    
    
}
