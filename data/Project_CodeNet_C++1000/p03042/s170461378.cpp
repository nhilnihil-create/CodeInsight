#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector < long long > vll;
typedef pair < long long, long long > pll;
typedef pair < int, int > pii;
typedef vector < int > vii;

const int N = 1e5 + 5;
const ll mod = 1e9 + 7;

int main(){
int a;
scanf("%d",&a);
int L = a/100; // it will divide the first part of the string
int R = a%100;
if(1<=L&&L<=12){
if(1<=R&&R<=12)printf("AMBIGUOUS\n");
else printf("MMYY\n");
}else{
if(1<=R&&R<=12)printf("YYMM\n");
else printf("NA\n");
}
}








