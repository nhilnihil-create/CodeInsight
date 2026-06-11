#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    double  a[n];
    double total=0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        total+=a[i];
    }
    double ave=total/n;
    int ans=0;
    double com=1e9;
    for(int i=0;i<n;i++){
        if(ave>=a[i]){
            if(ave-a[i]<com){
                com=ave-a[i];
                ans=i;
            }
        }
        else{
            if(a[i]-ave<com){
                com=a[i]-ave;
                ans=i;
            }
        }
        
    }
    cout << ans << endl;
}