#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define INF 100000000
int main(){
    ll A,B;
    cin>>A>>B;
    if(A>B)     cout<<(A+A-1);
    if(A<B)     cout<<(B+B-1);
    if(A==B)    cout<<(A+B);
}