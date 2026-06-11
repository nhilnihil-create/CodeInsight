#include<iostream>
using namespace std;
int main()
{
    int a,b,max,result;
    cin >> a >> b;
    if(a>=3 && b<=20)
    {
        if(a!=b)
            {
                if(a>b) max=a;
                else max=b;
                result=(max*2)-1;
                cout << result << endl;
            }
        else
            cout << a*2 << endl;
    }
    return 0;
}
