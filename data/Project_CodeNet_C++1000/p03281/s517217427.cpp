#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;

    int sum=0;
    for(int i=1;i<=n;i+=2){
        int sum2=0;
        for(int j=1;j<=i;j++){
            if(i%j==0) sum2++;
        }

        if(sum2==8) sum++;
    }
    
    cout<<sum<<endl;
    
}