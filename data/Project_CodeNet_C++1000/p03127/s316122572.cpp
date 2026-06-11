#include <bits/stdc++.h>
#include <string>
#include <algorithm>
#include <math.h>

#define N_size 100000000000

using namespace std;

int mygcd(long long x,long long y){
    if(x <= y){
        if(x == 0)
            return y;
        else
            return mygcd(y%x,x);      
    }else{
        if(y == 0)
            return x;
        else
        {
            return mygcd(y,x%y);
        }
        
    }
}

int main(){
    long long N;
    cin >> N;
    long long min_gcd = N_size;
    vector<long long> A(N);

    for(long long i = 0;i < N;i++){
        cin >> A.at(i);
    }

    for(long long i = 0;i < N - 1;i++){
        if(min_gcd > mygcd(A.at(i),A.at(i+1)))
            min_gcd = mygcd(A.at(i),A.at(i+1));
        if(min_gcd == 1)
            break;

    }

    cout << min_gcd << endl;

    

}