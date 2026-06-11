#include<iostream>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<set>
#include<math.h>
#include<vector>
#include<map>
#include<cassert>
#include<functional>

using namespace std;

int main(){
    long long n,a,b,c,d,e;
    cin >> n ;
    cin >> a >> b >> c >> d >> e;
    long long nums[5] = {a,b,c,d,e};
    long long max = 0;
    for(int i = 0;i < 5;i++){
        if(max < (n-1)/nums[i]){
          max = (n-1)/nums[i];
        }
    }
    long long t = 0;
    t += max + 5;
    cout << t << endl;

}