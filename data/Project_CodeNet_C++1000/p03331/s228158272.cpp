#include<iostream>
#include<string>
#include<math.h>
using namespace std;

int digit(int n, int j){
    int N[10];
    int i=1;
    while(n>0){
        N[i]= n%10;
        n /= 10;
        i++;
    }
    return N[j];
}
int keta(int n){
    int c=1;
    while(n>0){
        n /= 10;
        c++;
    }
    return c-1;
}

int main(){
    int N, A, B, sum=0, summin=9999999;
    cin >> N;
    for(int A=1; A<=N/2; A++){
        B=N-A;
        sum=0;
        for(int i=1; i<=keta(A); i++){
            sum += digit(A, i);
        }
        for(int i=1; i<=keta(B); i++){
            sum += digit(B, i);
        }
        if(summin>sum){
            summin = sum;
        }
        //cout << "A=" << A << " sum=" << sum << " summin=" << summin << endl;
    }
    cout << summin << endl;
    
    return 0;
}
