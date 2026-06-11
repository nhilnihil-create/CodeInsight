#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

int main(){
    int a[3];
    for(int i=0;i<3;i++){
        cin>>a[i];
    }
    sort(a,a+3);
    cout<<a[0]+a[1]+10*a[2]<<endl;

    return 0;
}