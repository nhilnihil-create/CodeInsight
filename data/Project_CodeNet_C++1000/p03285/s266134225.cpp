#include <algorithm>
#include <iostream>
#include <string>

#include <vector>

#include <functional>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int c, d, sum;
    bool flag = false;

    for (int i = 0; i < 101; i++)
    {
        for (int j = 0; j < 101; j++)
        {
            sum = 4 * i + 7 * j;
            if (sum == N)
                flag = true;
        }
    }
    if(flag){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

}