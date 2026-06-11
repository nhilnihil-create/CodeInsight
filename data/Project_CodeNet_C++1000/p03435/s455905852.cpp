#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<vector<int> > c(3, vector<int>(3));
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> c[i][j];
        }
        
    }

    int num = c[0][0];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            c[i][j] -= num;
        }
        
    }

    vector<int> a(3);
    vector<int> b(3);
    for (int i = 1; i < 3; i++)
    {
        b[i] = c[0][i];
    }
    for (int i = 1; i < 3; i++)
    {
        a[i] = c[i][0];
    }
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (c[i][j] != a[i] + b[j])
            {
                cout << "No" << endl;
                return 0;
            }
            
        }
        
    }

    cout << "Yes" << endl;
    
    return 0;
}