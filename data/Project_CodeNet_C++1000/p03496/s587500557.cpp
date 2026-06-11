#include <bits/stdc++.h>
using namespace std;


int main()
{
    int N;
    cin >> N;
    vector<int> a(N);
    for( int i = 0; i < N; ++i ) cin >> a[i];

    int max = *max_element( a.begin(), a.end() );
    int min = *min_element( a.begin(), a.end() );
    
    cout << 2*N - 1 << endl;
    if( abs(max) > abs(min) ){
        int maxi = distance( a.begin(), max_element( a.begin(), a.end() ) ) + 1;
        for( int i = 1; i <= N; ++i ) cout << maxi << " " << i << endl;
        for( int i = 1; i <  N; ++i ) cout << i << " " << i+1 << endl;
    }else{
        int mini = distance( a.begin(), min_element( a.begin(), a.end() ) ) + 1;
        for( int i = 1; i <= N; ++i ) cout << mini << " " << i << endl;
        for( int i = N; i >= 2; --i ) cout << i << " " << i-1 << endl;
    }
    return 0;
}