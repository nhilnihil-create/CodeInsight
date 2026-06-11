#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define PI 3.141592
#define all(a) (a).begin(), (a).end()
#define fi first
#define se second

int main(){
    int S;
    scanf("%d", &S);
    int L = S / 100;
    int R = S % 100;
    if(1<=L&&L<=12){
        if(1<=R&&R<=12)printf("AMBIGUOUS\n");
        else printf("MMYY\n");
    }else{
        if(1<=R&&R<=12)printf("YYMM\n");
        else printf("NA\n");
    }
}
