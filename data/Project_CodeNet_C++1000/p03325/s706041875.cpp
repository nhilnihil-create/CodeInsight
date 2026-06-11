#include <iostream>
#include <vector>
using namespace std;
int main(void){
    int n,i,ans=0;
    cin >> n;
    vector<long long int>a(n);
    for(i=0;i<n;i++){
        cin >> a[i];
    }
    for(i=0;i<n;i++){
        while(a[i]%2==0){
            a[i] = a[i]/2;
            ans++;
        }
    }
    cout << ans;
}