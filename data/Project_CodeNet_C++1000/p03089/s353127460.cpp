#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int n , b[101] , a[101] = {};
    bool f = true;

    cin >> n;
    for(int i=0 ;i<n ;i++ ){
        cin >> b[i];
        if( b[i] > i + 1 ){
            f = false;
        }
    }

    if(f){
        for(int i=0 ;i<n ;i++ ){
            for(int j=99 ;j>=b[i] - 1 ;j-- ){
                a[j+1] = a[j];
            }

            a[ b[i] - 1] = b[i];
        }

        for(int i=0; a[i] != 0 ;i++ ){
            cout << a[i];
            if(a[i+1] != 0){
                cout << ' ';
            }
        }
    } else {
        cout << -1;
    }
    cout << endl;

    return (0);
}