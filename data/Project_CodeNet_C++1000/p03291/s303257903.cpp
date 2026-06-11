#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
int mulMod(long long a, long long b) {
    a *= b;
    a %= mod;
    return (int)a;
}
int addMod(int a, int b) {
    long long c = a + b;
    if(c >= mod) {
        c -= mod;
    }
    return (int)c;
}
vector<int> readArray(int n){
    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    return arr;
}
void printArray(vector<int> &arr) {
    for(int a: arr)
        cout<<a<<" ";
    cout<<endl;
}

int main() {

    string x;
    cin>>x;
  	int n = x.length();
    long long c=0,bc=0,abc=0;
    int multi=1;
    reverse(x.begin(),x.end());
    for(int i=0;i<n;i++) {
        if(x[i]=='A') {
            abc=(abc+bc)%mod;
        }
        if(x[i]=='B') {
            bc=(bc+c)%mod;
        }
        if(x[i]=='C') {
            c=(c+multi)%mod;
        }
        if(x[i]=='?') {
            abc=(abc*3LL)%mod;
            abc=(abc+bc)%mod;
            bc=(bc*3LL)%mod;
            bc=(bc+c)%mod;
            c=(c*3LL)%mod;
            c=(c+multi)%mod;
            multi=(multi*3LL)%mod;
        }
    }
    cout<<(abc%mod)<<endl;
}
