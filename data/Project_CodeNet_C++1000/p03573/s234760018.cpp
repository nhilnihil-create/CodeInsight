#include <iostream>

using namespace std;

int main()
{
    int n,x[3];
    for(int i=0;i<3;i++)
    {
        cin>>x[i];
    }
    if (x[0]==x[1])
        n=x[2];
    else if(x[0]==x[2])
        n=x[1];
    else
        n=x[0];
    cout << n << endl;
    return 0;
}
