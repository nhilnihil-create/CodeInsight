#include <iostream>
#include <map>

using namespace std;

int main(int argc, char const *argv[])
{
    int N, M;
    cin >> N >> M;
    map<int, int> drink;
    int inA, inB;
    for (int i = 0; i < N; i++)
    {
        cin >> inA >> inB;
        drink[inA] += inB;
    }
    
    long long ans = 0;
    for (auto itr = drink.begin(); itr != drink.end(); itr++)
    {
        if ((itr -> second) > M)
        {
            ans += (long long)(itr -> first) * (long long)M;
            break;
        }else
        {
            ans += (long long)(itr -> first) * (long long)(itr -> second);
            M -= (itr -> second);
        }
        
    }

    cout << ans << endl;

    return 0;
}