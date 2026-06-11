#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<string>
#include<cmath>

using namespace std;

int main(){
	long N,P;
    cin>>N; cin>>P;
    long zantei = 1;
    long temp;
    if(N == 1){
        zantei = P;
    }else if(P == 1 || N > 39){

    }else{
        for(long i=2;i<=P;i++){
            temp = pow(i,N);

            if(temp > P){break;}
            if(P % temp == 0){
                zantei = i;
            }
        }
    }

    cout<<zantei<<endl;
	
	
}
