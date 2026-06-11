#include <iostream>

using namespace std;

int main()
{
    int N, D, X, val;
    int A[100];
    int day[100] = {0};

    cin >> N >> D >> X;

    for( int i=0; i<N; i++ )
        cin >> A[i];

    day[0] = N;

    for( int i=0; i<N; i++ )
    {
        if( A[i] >= D )
            continue;

        for( int j=1; j<D; j++ )
        {
            val = A[i] * j;
            if( val < D )
                day[val]++;
        }
    }

    for( int i=0; i<D; i++ )
    {
        if( day[i] != 0 )
            X += day[i];
    }

    cout << X << endl;
    
    return 0;
}