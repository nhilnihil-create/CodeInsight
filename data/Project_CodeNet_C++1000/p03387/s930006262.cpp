#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<int>a(3);
    for(int i=0;i<3;i++)cin>>a[i];
    sort(a.begin(),a.end());
    int cnt=0;
    while(a[1]<a[2]){
        a[0]++;
        a[1]++;
        cnt++;
    }
    if((a[2]-a[0])%2==0){
        cnt+=(a[2]-a[0])/2;
    }else{
        cnt++;
        cnt+=(a[2]+1-a[0])/2;
    }
    cout<<cnt<<endl;
    return 0;
}