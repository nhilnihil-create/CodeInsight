#include <bits/stdc++.h>
using namespace std;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define INF 100000000
typedef long long ll;
 
int main(){
    string a,b;
    cin>>a>>b;
    if(a[0]==b[2]&&a[1]==b[1]&&a[2]==b[0])cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}