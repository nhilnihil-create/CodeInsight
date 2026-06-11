#include <bits/stdc++.h>
using namespace std;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define INF 100000000
typedef long long ll;

int main(){
    string n;
    cin>>n;
    if(n[0]=='1')n[0]='9';
    else if(n[0]=='9')n[0]='1';
  
    if(n[1]=='1')n[1]='9';
    else if(n[1]=='9')n[1]='1';
  
    if(n[2]=='1')n[2]='9';
    else if(n[2]=='9')n[2]='1';
  
    cout<<n;
    return 0;
}