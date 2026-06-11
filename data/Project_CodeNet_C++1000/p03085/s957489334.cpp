#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define INF 100000000
int main(){
    string b;
    cin>>b;
    if(b[0]=='A')cout<<'T';
    if(b[0]=='T')cout<<'A';
    if(b[0]=='G')cout<<'C';
    if(b[0]=='C')cout<<'G';
}