#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using Vec = vector<int>;


int main() {
    int a,b,k;

    cin>>a>>b>>k;

    int x=a;
    if(k>b-a+1){

        for(int i=0;i<b-a+1;i++){

        cout<<x<<endl;
        x++;
    }

    }
    else{
        for(int i=0;i<k;i++){

        cout<<x<<endl;
        x++;
    }
    }

    int begin=b-k+1;

    if(begin<=x){

        while(x<=b){
            cout<<x<<endl;
            x++;
        }

    }
    else{
        while(begin<=b){

            cout<<begin<<endl;
            begin++;
        }
        
    }



    

}