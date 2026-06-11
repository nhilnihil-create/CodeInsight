#include<bits/stdc++.h>
using namespace std;

int main(void){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; ++i)
        cin >> a[i];
    
    sort(a.begin(), a.end(), greater<int> ());

    int al = 0, b=0;
    for(int i=0; i<n; ++i){
        if(i&1)
            b += a[i];
        else
            al += a[i];
    }

    cout << al-b ;
    return 0;
}
