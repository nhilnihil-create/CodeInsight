#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >>N;
    vector<int>vec(N);
    for(int i=0;i<N;i++){
        vec.at(i)=1+i;
    }
    int A,B;
    cin >>A>>B;
    int count =0;
    for(int j=0;j<N;j++){
        int a=0;
        if(vec.at(j)<=9){
           if(A<=vec.at(j)&&vec.at(j)<=B){
               count += vec.at(j);
           }
        }
        else if(10<=vec.at(j)&&vec.at(j)<=99){
            for(int i=1;i<=10;i*=10){
                a+=vec.at(j)/i%10;
            }
            if(A<=a&&a<=B){
                count += vec.at(j);
            }
        }
        else if(100<=vec.at(j)&&vec.at(j)<=999){
            for(int i=1;i<=100;i*=10){
                a+=vec.at(j)/i%10;
            }
            if(A<=a&&a<=B){
                count += vec.at(j);
            }
        }
        else if (1000<=vec.at(j)&&vec.at(j)<=9999){
            for(int i=1;i<=1000;i*=10){
                a+=vec.at(j)/i%10;
            }
            if(A<=a&&a<=B){
                count += vec.at(j);
            }
        }
        else if(vec.at(j)==10000){
                count += vec.at(j);
        }
    }
    cout << count <<endl;
}