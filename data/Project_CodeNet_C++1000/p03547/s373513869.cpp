#include <bits/stdc++.h>
using namespace std;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define INF 100000000
typedef long long ll;
 
int main(){
    char a,b;
    cin>>a>>b;
    if(a>b)cout<<'>';
    else if(a<b)cout<<'<';
    else cout<<'=';
    return 0;
}