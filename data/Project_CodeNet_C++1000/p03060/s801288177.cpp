#include<bits/stdc++.h>
using namespace std;
#define N 100010
#define ll long long
int main()
{
    int n;
    cin>>n;
    int a[n],b[n];
    for(int i = 0; i < n; i++){
        cin>>a[i];
    } 
    for(int i = 0; i < n; i++){
        cin>>b[i];
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(a[i] >= b[i]){
            ans += a[i] - b[i];
        }
    }
    cout<<ans;
}
