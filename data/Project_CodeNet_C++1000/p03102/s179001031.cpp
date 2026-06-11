#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int testcase=1;
    //cin>>testcase;
    for(int p=0;p<testcase;p++){
    ll n=0,m=0,c=0;
    cin>>n>>m>>c;
    ll counter=0;
    int array1[m]={0};
    for(int i=0;i<m;i++)
        cin>>array1[i];
    int array[20][20]={0};
    for(int i=0;i<n;i++){

        for(int j=0;j<m;j++){
            cin>>array[i][j];

        }
    }
    for(int i=0;i<n;i++){
        ll sum=0;
        for(int j=0;j<m;j++){
            sum+=array[i][j]*array1[j];
        }
        if(sum+c>0)
            counter++;
    }
    cout<<counter;


    }

    return 0;
}
