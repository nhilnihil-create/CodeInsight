#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N,sum;
    cin>>N;
    int a[N];
    for(int i=0; i<N; i++){
        cin>>a[i];
    }
    sort(a,a+N);
    sum=a[N-1]/2;
    for(int i=0; i<N-1; i++)
        sum+=a[i];
    cout<<sum<<endl;
}