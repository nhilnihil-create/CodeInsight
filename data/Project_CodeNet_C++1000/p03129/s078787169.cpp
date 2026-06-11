#include<bits/stdc++.h>
using namespace std;
int n,m,a;
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i+=2){
        a++;
    }
    if(a>=m)
        cout<<"YES";
    else
        cout<<"NO";
}
