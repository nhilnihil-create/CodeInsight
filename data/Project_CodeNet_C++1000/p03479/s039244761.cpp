#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long int x,y;
    cin>>x>>y;
    long long int count=0;
    while (y/x!=0) {
        x*=2;
        count++;
    }
    cout<<count<<endl;
}