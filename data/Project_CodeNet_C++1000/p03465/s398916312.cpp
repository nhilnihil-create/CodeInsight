#include<bits/stdc++.h>
using namespace std;

const int SIZE=2000*2000+1;
using Bit=bitset<SIZE>;
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    Bit bit;
    bit[0]=true;
    for(int i=0;i<n;i++){
        bit=bit|(bit<<a[i]);
    }
    int v=accumulate(a.begin(),a.end(),0);
    for(int i=(v+1)/2;i<=v;i++){
        if(bit[i]){
            cout<<i<<endl;
            return 0;
        }
    }
    return 0;
}