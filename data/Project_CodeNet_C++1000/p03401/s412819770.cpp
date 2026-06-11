#include<bits/stdc++.h>
using namespace std;
int b[100005];
int main(){
    int n;
    cin >> n;
    int a[n+2];
    a[0]=0;
    for(int i=1;i<n+1;i++){
        cin >> a[i];
        b[i] = b[i-1] + abs(a[i]-a[i-1]);
    }
    b[n+1] = b[n] + abs(a[0]-a[n]);
    a[n+1]=0;
    for(int i=1;i<n+1;i++)cout << b[n+1] - abs(a[i]-a[i-1])-abs(a[i+1]-a[i])+abs(a[i+1]-a[i-1]) << endl;
}