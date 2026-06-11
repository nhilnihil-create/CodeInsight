#include <bits/stdc++.h>
using namespace std;

int main(){

    long long int k,a,b;
    cin >> k >> a >> b;
    long long int count=1;

    if(b-a<=2 || k-(a-1)<2){
        count+=k;
 //       cout << endl ;
    }
    else{
        if((k-(a-1))%2==1){
            count+=a;
            count+=(k-a)*(b-a)/2;
        }
        else{
            count+=a-1;
            count+=(k-(a-1))*(b-a)/2;
        }
    }
    cout << count << endl;
}