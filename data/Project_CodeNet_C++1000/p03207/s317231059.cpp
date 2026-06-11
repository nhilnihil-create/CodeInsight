#include <iostream>
using namespace std;

int main(){
    int N,i,max,sum;
    cin >> N;
    int p[N];
    for ( i = 0 ; i < N ; i++ )
    {
        cin >> p[i];
    }

    max = p[0];
    sum = 0;

    for( i = 1 ; i < N ; i++ )
    {
        if (max < p[i]) max = p[i];
    }

    for (i = 0; i < N; i++)
    {
        sum += p[i];
    }
    
    cout << sum - max/2 << endl;
    
    return 0;
}