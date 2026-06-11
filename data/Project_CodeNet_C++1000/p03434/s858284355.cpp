#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int N;

    int A[N+1];

    cin >> N;
    for ( int i = 0; i < N; i ++ ) {
        cin >> A[i];
    }

    sort( A, A+N);
    
    int d = 0;
    int i = N-1;
    while ( 1 ) {
        d += A[i];
        i --;
        if ( i < 0 ) break;
        d -= A[i];
        i --;
        if ( i < 0 ) break;
    }

    cout << d << endl;


    return 0;
}