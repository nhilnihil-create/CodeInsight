#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, j, k=10000;
    bool res = false;

    cin>>n;

    for(i=1; i<10; i++){

        if(n/i == 111 && n%i == 0){
            res = true;
        }
    }
    if(res)
        cout<<n;
    else{

        while(k){
            n =n +1;
            for(i=1; i<10; i++){

                if(n/i == 111 && n%i == 0){
                    res = true;
                }
            }
            if(res){
                cout<<n;
                break;
            }

            k--;
        }

    }



}
