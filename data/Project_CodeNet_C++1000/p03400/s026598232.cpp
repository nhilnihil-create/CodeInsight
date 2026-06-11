#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,d,x;
    cin >> n >> d >> x;
    int a[n];
    for(int i=0;i<n;i++)cin >> a[i];
    for(int i=1;i<d+1;i++){
        for(int j=0;j<n;j++){
            if(a[j]==1)x++;
            else if(i%a[j]==1)x++;
        }
    }
    cout << x << endl;
}