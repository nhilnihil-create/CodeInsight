#include <iostream>

using namespace std;

int main()
{
    int N , A , x ;
    cin >> N >> A ;

    x = N / 500 ;
    N = N -(500* x) ;
    if((A - N)>= 0)
    {
        cout << "Yes" << endl;
    }else
    {
        cout << "No" << endl;
    }
    return 0;
}
