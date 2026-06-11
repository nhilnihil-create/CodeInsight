#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, c;
    cin >> n >> m >> c ;
    int b[m];
    int i,j;
    for(i=0; i<m; i++){
        cin >> b[i];
    }
    int d =0;
    for(i=0; i<n; i++){
        int a[m];
        int sum = 0;
        for(j=0; j<m; j++){
            cin >> a[j];
            sum += a[j]*b[j];
        }
        //cout << sum << endl;
        if(sum+c > 0){
            d++;
        }
    }
    cout << d << endl;
}
