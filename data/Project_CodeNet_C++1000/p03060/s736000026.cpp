#include<bits/stdc++.h>
using namespace std;
#define first ff
#define second ss
#define ll long long int
int main()
{
    int n;
    cin>>n;
    int a[n]={0},b[n]={0};
    int x,y;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    int mx=0;

    for(int i=0;i<n;i++){
         if(a[i]-b[i]>0) mx+=(a[i]-b[i]);
    }

cout<<mx;

}
