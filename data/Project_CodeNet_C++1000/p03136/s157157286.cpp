#include <iostream>
using namespace std;

int main()
{
    int n = 0;
    int edge = 0;
    int max,count = 0;
    cin >> n;
    while(n > 0)
    {
        cin >> edge;
        if(edge > max)
            max = edge;
        count += edge;
        --n;
    }
    if(count > (max << 1))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}