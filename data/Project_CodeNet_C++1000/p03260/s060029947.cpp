#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    //the thing is to never rush and play it patience
    int a[2];
    cin>>a[0]>>a[1];
    sort(a,a+2);
    if(a[1]==3){
        if(a[0]%2==0)cout<<"No";
        else cout<<"Yes";
    }else if(a[1]==1)cout<<"Yes";
    else cout<<"No";
}
