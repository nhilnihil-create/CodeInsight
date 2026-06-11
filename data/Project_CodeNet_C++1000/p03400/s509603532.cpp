#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n,d,x,i,cnt,j;
    cnt = 0;

    cin >> n >> d >> x;

    vector<int> A(n);
    for(i=0; i<n; i++){
        cin >> A.at(i);
    }

    for(i=0; i<n; i++){
        for(j=0; j * A.at(i) + 1 <= d; j++){
            cnt++;
        }
    }

    cout << x + cnt << endl;
    
    return 0;
}
