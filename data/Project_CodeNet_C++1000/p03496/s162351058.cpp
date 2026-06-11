#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    long long a[n];
    int pos = 0;
    for(int i=0; i<n; i++){
        cin >> a[i];
        if(a[i] >= 0) pos++;
    }
    auto max = max_element(a,a+n);
    auto min = min_element(a,a+n);
    if(*max <= 0){
        cout << n-1 << endl;
        for(int i=n; i>=2; i--){
            cout << i << ' ' << i-1 << endl;
        }
    }
    else if(*min >= 0){
        cout << n-1 << endl;
        for(int i=1; i<=n-1; i++){
            cout << i << ' ' << i+1 << endl;
        }
    }
    else if(*max >= -*min){
        int max_index = max - a + 1;
        cout << n-1+(n-pos) << endl;
        for(int i=0; i<n; i++){
            if(a[i] < 0){
                cout << max_index << ' ' << i+1 << endl;
            }
        }
        for(int i=1; i<=n-1; i++){
            cout << i << ' ' << i+1 << endl;
        }
    }
    else{
        int min_index = min -a +1;
        cout << n-1+pos << endl;
        for(int i=0; i<n; i++){
            if(a[i] >= 0){
                cout << min_index << ' ' << i+1 << endl;
            }
        }
        for(int i=n; i>=2; i--){
            cout << i << ' ' << i-1 << endl;
        }
    }
    return 0;
}
