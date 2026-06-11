#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

using std::cout;
using std::cin;
using std::endl;
using std::pow;
using std::vector;
using std::string;

int main(){
    int res=0,n,i,j;
    cin >> n;
    for(i=1;i<=n;i+=2){
        int num = i,count = 1;
        for(j=2;num!=1;j++){
            int t=1;
            while(num % j == 0){
                t++;
                num /= j;
            }
            count *= t;
        }
        if(count == 8) res++;
    }
    cout << res;
}