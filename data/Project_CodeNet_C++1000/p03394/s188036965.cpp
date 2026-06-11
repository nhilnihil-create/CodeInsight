#include <bits/stdc++.h>
using namespace std;
#define int long long



signed main(){
    int n;
    cin>>n;
    if(n==3){
        
        cout <<"2 5 63";
       
    }
    else{
        int sum=5,i=2;
        cout <<4<<' ';
        sum+=4;i++;
        int t=0,k=5;
        while(i<n&&k<30000){
            cout <<k<<' ';sum+=k;
            i++;k+=30;
        }
        k=25;
        while(i<n&&k<30000){
            cout <<k<<' ';sum+=k;
            i++;k+=30;
        }
        k=9;
        while(i<n&&k<30000){
            cout <<k<<' ';sum+=k;
            i++;k+=6;
        }
        k=6;
        while(i<n&&k<30000){
            cout <<k<<' ';sum+=k;
            i++;k+=2;
        }
        int r=30 - sum%30;
        if(r%2==0){
            cout <<3<<' ';
            if(r==30)cout <<2;
            else cout <<30000-30+(r+2);
        }else{
            cout <<30000<<' ';
            cout << 29940+r+5;
        }


    }

    return 0;
}