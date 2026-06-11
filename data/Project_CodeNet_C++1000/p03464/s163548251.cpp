#include <bits/stdc++.h>
using namespace std;

int main(){
    int k;
    cin >> k;

    vector<long long int> a(k);
    for(int i=0; i<k; i++){
        cin >> a[i];
    }
    reverse(a.begin(),a.end());

    if(a[0] != 2){
        cout << -1 << endl;
        return 0;
    }

    long long int nmax = 2, nmin = 2;
    for(int i=0; i+1<k; i++){
        //cout << nmax << " " << nmin << endl;
        long long int x = (nmax + a[i] - 1) / a[i+1] * a[i+1];
        long long int y = ((nmin - 1) / a[i+1] + 1) * a[i+1];

        if(x < y){
            cout << -1 << endl;
            return 0;
        }
        
        nmax = x;
        nmin = y;
    }
    nmax += a[k-1] - 1;
    cout << nmin << " " << nmax << endl;
    return 0;
}