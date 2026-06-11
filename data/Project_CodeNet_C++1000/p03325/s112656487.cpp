/******************************************************************************

            EYENINE,THE ELDER_WAND!!!
            THE ROOT OVER MINUS EIGTHY ONE!!

*******************************************************************************/

#include<bits/stdc++.h>
using namespace std;
int a[10005];
int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,sum=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        while(a[i]%2==0){
            a[i]/=2;
            sum++;
        }
    }
    cout<<sum<<endl;

    return 0;
}
