#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    vector<int> t, x, y;
    t.resize(N);
    x.resize(N);
    y.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> t[i] >> x[i] >> y[i];
    }

    int prvt = 0, prvx = 0, prvy = 0;
    for (int i = 0; i < N; i++)
    {
        if (t[i] - prvt < abs(x[i] - prvx) + abs(y[i] - prvy))
        {
            cout << "No" << endl;
            return 0;
        }else
        {
            if ((t[i] - prvt - abs(x[i] - prvx) - abs(y[i] - prvy)) % 2 != 0)
            {
                cout << "No" << endl;
                return 0;
            }
            
        }
        prvt = t[i];
        prvx = x[i];
        prvy = y[i];
           
    }
    
    cout << "Yes" << endl;
    
    return 0;
}