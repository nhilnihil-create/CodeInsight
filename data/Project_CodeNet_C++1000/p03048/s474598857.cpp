#include <bits/stdc++.h>
using namespace std;

int R,G,B,N;

int main(){
    cin>>R>>G>>B>>N;
    long long count=0;
    for(int r=0;r<=3000;r++){
        for(int g=0;g<=3000;g++){
            if((N-r*R-g*G)%B==0&&(N-r*R-g*G)>=0)count++;        }
    }
    cout<<count<<endl;
}