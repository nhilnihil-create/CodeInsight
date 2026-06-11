#include <bits/stdc++.h>
using namespace std;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define INF 100000000
typedef long long ll;

int main(){
    string S;
    cin>>S;
    sort(S.begin(),S.end());
    if(S=="abc")cout<<"Yes";
    else cout<<"No";
    return 0;
}