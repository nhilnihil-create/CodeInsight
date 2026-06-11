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
    int a;
    scanf("%d",&a);
    for(int i=0;i<a;i++){
        int t;
        scanf("%s%d",in,&t);
        string tmp=in;
        p[i]=make_pair(make_pair(in,-t),i);
    }
    std::sort(p,p+a);
    for(int i=0;i<a;i++)printf("%d\n",p[i].second+1);
}