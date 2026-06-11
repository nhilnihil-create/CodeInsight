#include<bits/stdc++.h>
using namespace std;

int N,K;
string a;



int main(){
    cin>>N>>K>>a;
    a[K-1]=a[K-1]-'A'+'a';
    cout<<a;
}