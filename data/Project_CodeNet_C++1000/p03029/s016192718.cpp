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
    int A,P;
    cin >> A >> P;

    P+= 3*A;
    int num =P/2;
    
    cout << num;
}
