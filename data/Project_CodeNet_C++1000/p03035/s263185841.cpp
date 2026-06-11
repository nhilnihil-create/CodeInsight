#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define INF 100000000
int main(){
    ll A,B;
    cin>>A>>B;
    if(A>=13)cout<<B;
    else if(6<=A&&A<13)cout<<(B/2);
    else cout<<0;
}