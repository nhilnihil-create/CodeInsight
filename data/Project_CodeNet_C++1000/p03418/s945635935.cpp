#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

int main(){
    long long n,k;
    cin>>n>>k;
    long long result = 0;
    if (n == k){
        cout<<0<<endl;
    }
    else if (k == 0){
        long long k = n*n;
        cout<<k<<endl;
    }
    else{
        for (int i = 1;i <= n - k; i ++){
            int b = i + k;
            result += n/b*i;
            if (n%b - k >= 0){
                result += n%b - k+1;
            }

        }
        cout<<result<<endl;
    }
}
