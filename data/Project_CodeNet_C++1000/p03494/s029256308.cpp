#include <bits/stdc++.h>
using namespace std;
long long n,a[200],k,x,t,j;

int main(){
ios_base::sync_with_stdio(0);
cin.tie(0);cout.tie(0);
cin>>n;
for(int i=0;i<n;i++){
    cin>>a[i];
    if(a[i]%2!=0)k++;}
    if(k>0)cout<<0;
    else {
            for( j=1;j<200;j++){

        for(int i=0;i<n;i++){
            if(a[i]%2==0){
                a[i]/=2;t++;

                if(a[i]%2!=0)x++;
            }

        }if(x>0)break;
        }
        cout<<j;
    }

}

