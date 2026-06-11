#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define f(i,j,n) for(int i=j;i<=n;i++)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    if(n % 2)
        cout << n * 2;
    else
        cout << n;
} 
