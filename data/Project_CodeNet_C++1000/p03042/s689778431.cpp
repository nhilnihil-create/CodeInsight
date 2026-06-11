#include<bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define PI 3.14159265358979323846264338327950L
using namespace std;
using P = pair<int,int>;
using ll = long long;
using namespace std;
char in[120];
pair<pair<string,int>,int> p[110];
int main(){
int a;scanf("%d",&a);
int L=a/100;
int R=a%100;
if(1<=L&&L<=12){
if(1<=R&&R<=12)printf("AMBIGUOUS\n");
else printf("MMYY\n");
}else{
if(1<=R&&R<=12)printf("YYMM\n");
else printf("NA\n");
}
}
