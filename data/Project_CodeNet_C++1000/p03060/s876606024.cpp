#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1e18
#define gap " "
#define pi 2 * acos (0.0)

int main()
{
    
    int n;
    cin>> n;
    int a[n],b[n];
    int s=0;
    for(int i=0;i<n;i++){
        cin>> a[i];
    }
    for (int i=0;i<n;i++){
        cin>> b[i];
    }
    for (int i=0;i<n;i++){
        if ((a[i]-b[i])>0) s=s+(a[i]-b[i]);
    }
    cout << s <<endl;

}
