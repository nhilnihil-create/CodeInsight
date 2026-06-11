#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;

int findDigitSum(int n){
    int sum=0;
    while(n>0){
        sum+=n%10;
        n/=10;
    }
    return sum;
}

int main(void){
    int n;cin>>n;
    int min = 100000;
    for(int i=1;i<n;i++){
        int j=n-i;
        int sum=findDigitSum(i)+findDigitSum(j);
        if(min>sum)min=sum;
    }
    cout<<min<<endl;
}

