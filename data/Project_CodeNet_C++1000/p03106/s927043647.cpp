#include<bits/stdc++.h>

using namespace std;

int main(){

    int a,b,k; cin>>a>>b>>k;

    int sum=0;

    int s=0;

    if(a>=b){

        for(int i=b;i>0;i--){

            if(a%i==0&&b%i==0) sum++;

            if(sum==k){

                s=i;

                break;

            }

        }

    }

    else if(a<b){

        for(int i=a;i>0;i--){

            if(a%i==0&&b%i==0) sum++;

            if(sum==k){

                s=i;

                break;

            }

        }

    }

    cout<<s<<endl;

}

