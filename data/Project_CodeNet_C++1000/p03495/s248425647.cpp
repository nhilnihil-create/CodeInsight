#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n,k;
    cin >> n >> k;
    int a[n];
    int p[200001] = {};
    for(int i = 0; i < n; i++){
        cin >> a[i];
        p[a[i]]++;
    }
    int count = 0;
    for(int i = 0; i < 200000; i++){
        if(p[i] > 0){
            count++;
        }
    }
    
    if(count <= k){
        cout << 0 << endl;
        return 0;
    }

    sort(p,p+200001);
    for(int i = 0; i < k; i++){
        n -= p[200000-i];
    }
    cout << n << endl;
    return 0;
}