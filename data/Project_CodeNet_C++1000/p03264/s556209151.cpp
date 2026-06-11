#include <iostream>

using namespace std;

int main()
{
    int x;
    cin >> x;
    int num [x];
    int c=1;
    int tot=0;
    int counter =0;
    for (int y=0;y<x;y++)
    {
        num [y]=c;
        c+=1;
        int z=1;
        for(int d=0;d<x;d++)
        {
            tot=0;
            tot=num[y]+z;
            z+=2;
            if (tot<=x)
            {
                counter++;
            }
        }
    }
    cout << counter;
    return 0;
}
