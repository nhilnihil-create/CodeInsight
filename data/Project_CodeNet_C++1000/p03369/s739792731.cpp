#include <iostream>

using namespace std;

int main()
{
    int m , i ;
    string S ;
    cin >> S ;
    m = 0 ;
    for(i=0 ; i <= 2 ; i++)
    {
        if(S[i] == 'o')
        {
            m = m + 100 ;
        }
    }
    cout << m + 700 << endl;
    return 0;
}
