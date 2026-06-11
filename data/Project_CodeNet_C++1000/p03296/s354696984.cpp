#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int main(){
    int n;
    int ans=0;
    cin >> n;
    int count=0;
    int a[110];
    for(int i=0;i<n;i++){
        cin>>a[i];
        count++;
        if(count==2){
            if(a[i] == a[i-1]){
                ans++;
                count--;
            }
            count--;
            
        }
    }
cout<<ans<<endl;
}
