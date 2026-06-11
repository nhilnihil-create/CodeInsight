/*|In The Name Of Allah|*/

#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+5;

const int mod = 1e9+7;

int n;
int cnt[N];

vector < int > primeFactors(long long num){
    vector < int > prm;
    while (num % 2 == 0){
        prm.push_back(2);
        num = num/2;
    }
    for (long long i = 3; i*i <= num; i = i + 2){
        while (num % i == 0){
            prm.push_back(i);
            num = num/i;
        }
    }
    if (num > 2)
        prm.push_back(num);
    return prm;
}

int go(int idx , int mul , int tk){
    if(mul > 75)
        return 0;
    if(idx > 100)
        return mul == 75;
    int ways = go(idx + 1 , mul * max(tk+1 , 1) , 0);
    if(tk + 1 <= cnt[idx])
        ways += go(idx , mul , tk + 1);
    return ways;
}

int main(){
    scanf("%d" , &n);
    for(int i = 1; i <= n; i++){
        vector < int > ret = primeFactors(i);
        for(auto v : ret){
            cnt[v]++;
        }
    }
    printf("%d\n" , go(1 , 1 , 0));
}