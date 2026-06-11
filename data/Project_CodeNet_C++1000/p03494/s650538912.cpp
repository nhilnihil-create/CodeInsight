#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<int> count(n, 0);
    for(int i = 0; i < n; i++){
        while(a[i] % 2 == 0){
            count[i]++;
            a[i] /= 2;
        }
    }

    int ans = 1001001001;
    for(int i = 0; i < n; i++){
        if(ans > count[i]) ans = count[i];
    }

    cout << ans << endl;
    return 0;
}