#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    long long ans=a[0];
    for(int i=1; i<n; i++){
        if(a[i]-a[i-1]>0){
            ans = ans + a[i] - a[i-1];
        }
    }
    cout << ans << endl;
    return 0;
}