#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int mod = ll(1e9 + 7), N = 1e5 + 5;

int call(int n){
    int c=0;
    while(n%2==0){
        c++;
        n=n>>1;
    }
    return c;
}

int main(){

    int n;cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int s=0;
    for(int i=0;i<n;i++) s+=call(a[i]);
    cout<<s;

}
