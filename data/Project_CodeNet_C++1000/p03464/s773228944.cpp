#include<bits/stdc++.h>
using namespace std;
int main(){
    int k;
    cin >> k;
    long a[k];
    for(int i=0;i<k;i++)cin >> a[i];
    bool chk = true;
    long upper = 2;
    long lower = 2;
    for(int i=k-1;i>=0;i--){
        if(upper%a[i] != 0)upper -= upper%a[i];
        if(lower%a[i] != 0)lower += a[i] - (lower%a[i]);
        if(upper<lower){
            chk = false;
            break;
        }
        upper += a[i]-1;
    }
    if(chk)cout<<lower<<" "<<upper<<endl;
    else cout<<-1<<endl;
}
