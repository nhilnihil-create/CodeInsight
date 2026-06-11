#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n;
    long long a = 0;
    int b = 0;
    scanf("%d",&n);
    while(n--){
        a++;
        int sum = 0;
        long long aa = a;
        while(aa){
            sum += (int)(aa % 10);
            aa /= 10;
        }
        if(sum + (b * 9) < a || (sum + (b * 9) == a && b > 0)){
            b++;
            a /= 10;
        }
        printf("%lld", a);
        for(int i=0;i<b;i++) printf("9");
        printf("\n");
    }
}