#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int>a(n);

    for(int i=0; i<n; i++){
        cin >> a[i];
        if(a[i]%2==1){
            cout << 0 << endl;
            return 0;
        }
    }
    int ans = 0;

    while(1){
        for(int i=0; i<n; i++){
            a[i] /= 2;
        }
        ans++;
        for(int i=0; i<n; i++){
            if(a[i]%2==1){
                cout << ans << endl;
                return 0;
            }
        }
    }
    
    return 0;
}