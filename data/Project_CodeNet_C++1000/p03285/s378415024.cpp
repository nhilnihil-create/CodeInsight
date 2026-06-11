#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    if(n % 4 == 0){
        cout<<"Yes"<<endl;
        return 0;
    }
    else if(n % 7 == 0){
        cout<<"Yes"<<endl;
        return 0;
    }
    else if(n % 11 == 0){
        cout<<"Yes"<<endl;
        return 0;
    }
    else{
        int temp = n;
        while(temp >= 4){
            temp -= 4;
            if(temp % 7 == 0){
                cout<<"Yes"<<endl;
                return 0;
            }
        }
        while(n >= 7){
            n -= 7;
            if(n % 4 == 0){
                cout<<"Yes"<<endl;
                return 0;
            }
        }
    }

    cout<<"No"<<endl;

}