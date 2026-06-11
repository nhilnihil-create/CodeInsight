#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

bool isPrime(int x){
    if(x==2){
        return true;
    }else if(x<2 || x%2==0){
        return false;
    }else{
        int i=3;
        while(i<=sqrt(x)){
            if(x%i==0){
                return false;
            }
            i+=2;
        }
        return true;
    }
}

int main(){
    int prime[100001];
    int index = 0;
    for(int i=3;i<100000;i+=2){
        if(isPrime(i) && isPrime((i+1)/2)){
            prime[index] = i;
            index++;
        }
    }
    int q;
    cin >> q;
    int ans[q];
    for(int i=0;i<q;i++){
        int l,r;
        cin >> l >> r;
        ans[i] = distance(lower_bound(prime,prime+index,l),upper_bound(prime,prime+index,r));
    }

    for(int i=0;i<q;i++){
        cout << ans[i] << endl;
    }
}