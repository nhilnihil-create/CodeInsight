#include <iostream>
#include <cmath>

using namespace std;

bool plusInteger(double a)
{
    if (floor(a) == ceil(a))
    {
        if (floor(a) >= 0)
        {
            return 1;
        }else
        {
            return 0;
        }
        
    }else
    {
        return 0;
    }
    
}

int main(int argc, char const *argv[])
{
    double R, G, B, N;
    cin >> R >> G >> B >> N;

    int sum = 0;
    double b;
    for (int r = 0; r * R <= N; r++)
    {
        for (int g = 0; g * G <= N; g++)
        {
            b = (N - R * r - G * g) / B;
            if (plusInteger(b)) sum++;
        }
        
    }
    
    cout << sum << endl;
    
    return 0;
}