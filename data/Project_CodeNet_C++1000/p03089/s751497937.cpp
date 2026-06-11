#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> b(n+1);
    for(int i = 1; i <= n; i++) cin >> b[i];

    vector<int> a(n+1);
    bool ok = true;
    for(int i = 0; i < n && ok; i++){
        ok = false;
        for(int j = n-i; j > 0; j--){
            if(b[j] == j){
                a[i] = b[j];
                ok = true;
                for(int k = j; k < n; k++){
                    b[k] = b[k+1];
                }
                break;
            }
        }
    }

    if(ok){
        for(int i = n-1; i >= 0; i--) cout << a[i] << endl;
    }else{
        cout << -1 << endl;
    }
    return 0;
}