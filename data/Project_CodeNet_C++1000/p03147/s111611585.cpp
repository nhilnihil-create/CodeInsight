#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define REPS(i,x) for(int i=1;i<=(int)(x);i++)
#define mp(a,b) make_pair(a, b)
#define pb push_back
#define eb emplace_back
#define ll long long
int main() {
    int t,x=0,c=0;
    cin>>t;
    int arr[t];
    REP(i,t)
    {
        cin>>arr[i];
    }
   int ar2[t]={0};
 int i=0,j=t-1;
while(1){
 while(i<=j)
 {
     if(x==1 && arr[i]==ar2[i]){c++;break;}
     while(arr[i]==ar2[i]){i++;}
     if(i>j) {break;}
     if(arr[i]>ar2[i]) { x=1;
         ar2[i]++;
     }
     if(x==1 && i==j){c++;break;}
     i++;
 }
 if(x==0)break;i=0;x=0;
    
}cout<<c<<endl;
}