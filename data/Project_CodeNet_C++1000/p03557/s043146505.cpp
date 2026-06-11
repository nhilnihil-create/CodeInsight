#include <bits/stdc++.h>
using namespace std;
int main() {
    long long N;
    cin>>N;
    long long a[N]={0};
    long long b[N]={0};
    long long c[N]={0};
    for(long long i=0;i<N;i++){
    cin>>a[i];}
    for(long long i=0;i<N;i++){
    cin>>b[i];}
    for(long long i=0;i<N;i++){
    cin>>c[i];}
    sort(a,a+N);
    sort(b,b+N);
    sort(c,c+N);
    long long counter=0;
    long long acount=0;
    long long ccount=0;
    for(long long i=0;i<N;i++){
    acount=lower_bound(a, a + N, b[i]) - a;
    ccount=c+N - upper_bound(c, c + N, b[i]);
    counter+=acount*ccount;}
    

    
    cout << counter << endl; // 10 (場外)
}
