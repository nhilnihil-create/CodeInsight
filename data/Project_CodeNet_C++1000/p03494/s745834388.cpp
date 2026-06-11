#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; ++i)
        cin >> a[i];

    int count = 0;
    while(1){
        for(int i=0; i<n; ++i){
            if(a[i]&1){
                cout << count;
                return 0;
            }
            a[i] /= 2;
        }
        count++;
    }
    return 0;
}