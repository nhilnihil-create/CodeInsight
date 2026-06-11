#include<bits/stdc++.h>
using namespace std;
int main(){


    int a[3];
    for(int i=0;i<3;i++){
        cin>>a[i];

    }

    sort(a,a+3,greater<int>());

    int res=(a[0]*10)+a[1]+a[2];
    cout<<res<<endl;

}
