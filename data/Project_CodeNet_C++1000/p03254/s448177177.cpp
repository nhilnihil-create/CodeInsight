#include <bits/stdc++.h>
using namespace std;

int N,x;
int a[110];

int main(){
    cin>>N>>x;

    for (int i = 0; i < N; i++)
    {
        cin>>a[i];
    }
    
    sort(a,a+N);

    long long sum=0;
    int ans=0;
    for (int i = 0; i < N; i++)
    {
        sum += a[i];
        if(sum<=x) ans++;

        if(i==N-1 && sum<x) ans--;
    }

    cout << ans << endl;

    return 0;
}
