#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
    int n;cin>>n;
    vector<int> a(n);
    double sum = 0;
    for(int i = 0; i<n; i++) {
        cin>>a[i];
        sum += a[i];
    }
    double ans = 110;
    int j;
    sum /= (double)n;

    for(int i = 0; i<n; i++) {
        if(ans > abs(sum - (double)a[i])){ ans = abs(sum - (double)a[i]);
        j = i;}
    }    
        cout << j << endl;
}