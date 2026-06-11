#include <bits/stdc++.h>
using namespace std;

int main(){
  
int a,b,c,X,sum,count;

cin >> a >> b >> c >> X;
count=0;

    for(int i=0; i<=a; i++){
        for(int j=0; j<=b; j++){
            for(int k=0; k<=c; k++){
                sum=i*500+j*100+k*50;
                if(sum == X)count++;
            }
        }
    }

    cout<< count <<endl;
}