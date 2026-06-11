#include <iostream>
#include <string>
#include <math.h>
#include <vector>
using namespace std;
int main()
{
    int ans, A, B, K, itr;
    int count = 0;
    vector<int> N;

    cin >> A >> B >> K;

    for (int i = 1; i <= min(A, B); i++)
    {
        if (A % i == 0 && B % i == 0)
        {
            N.push_back(i);
        }
    }
ans=N.at( N.size() - K);
    
    cout << ans << endl;
    return 0;
}
