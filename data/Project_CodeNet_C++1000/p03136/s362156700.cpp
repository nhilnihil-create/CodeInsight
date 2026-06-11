#include <iostream>

using namespace std;

int main()
{
    int n,l,max,sum;
    max = 0;
    sum = 0;
    cin >> n;

    for(int i = 0; i < n; ++i)
    {
        cin >> l;
        if(l > max)
        {
            sum += max;
            max = l;
        }
        else sum += l;
    }

    if(sum > max) cout << "Yes";
    else cout << "No";

    return 0;
}