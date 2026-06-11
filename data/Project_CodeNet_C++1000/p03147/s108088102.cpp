#include <iostream>
#include <vector>
using namespace std;
int main(void){
    int n,i,ans=0,x=0;
    cin >> n;
    vector<int> h(n);
    for(i=0;i<n;i++) cin >> h[i];
    for(i=0;i<n;i++){
        if(x<h[i]){
            ans+=h[i]-x;
            x = h[i];
        }
        else x = h[i];
    }
    cout << ans;
}