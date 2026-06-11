#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <iostream>
#include <set>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

const int mod = 1e9+7;
#define ll long long int
const double epsilon = 1e-7;

ll mi(ll x, ll y){
    if(x<y)return x;
    return y;
}
int main(void){
    int n;
    scanf("%d", &n);
    if(n == 3){
        printf("2 5 63\n");
        return 0;
    }
    printf("3 9 ");
    if(n % 3 != 0){
        int a;
        if(n%2==0)a = 15000;
        else a = 14999;
        for(int i = 0;i < n-2 && i < a;i++)printf("%d ", i * 2 + 2);
        for(int i = 0;i < n-2-a;i++)printf("%d ", i * 6 + 15);
    }else{
        int a;
        if(n%2==0 || n < 15002){
            a = 15000;
        for(int i = 0;i < n-2 && i < a;i++){
            if(i%3 == 0)printf("%d ", i * 2 + 6);
            if(i%3 == 1)printf("%d ",i * 2);
            if(i%3 == 2)printf("%d ",i * 2);
        }}else{
            a = 14999;
            for(int i = 0;i < n-2 && i < a;i++)printf("%d ", i * 2 + 2);
        }
        for(int i = 0;i < n-2-a;i++)printf("%d ", i*6+15);
    }
    printf("\n");
    return 0;
}
