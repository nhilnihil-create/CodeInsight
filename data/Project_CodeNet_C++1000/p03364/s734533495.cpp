#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
#include<deque>
#include<iomanip>
#include<tuple>
using namespace std;
typedef long long int LL;
typedef pair<int,int> P;
typedef pair<LL,int> LP;
const int INF=1<<30;
const LL MAX=1e9+7;

void array_show(int *array,int array_n,char middle=' '){
    for(int i=0;i<array_n;i++)printf("%d%c",array[i],(i!=array_n-1?middle:'\n'));
}
void array_show(LL *array,int array_n,char middle=' '){
    for(int i=0;i<array_n;i++)printf("%lld%c",array[i],(i!=array_n-1?middle:'\n'));
}

char ca[305][305];
int n,m;

int round(int a){
    if(a<0)a+=n;
    if(a>=n)a%=n;
    return a;
}

bool check(int t){
    int i,j;
    int x1,y1,x2,y2;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            x1=round(t+i),y1=j;
            x2=round(t+j),y2=i;
            if(ca[x1][y1]!=ca[x2][y2])return false;
        }
    }
    return true;
}

int main(){
    int i,j,k;
    int a,b,c;
    bool flag=false;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>ca[i];
    }
    a=0;
    for(i=-n+1;i<n;i++){
        if(check(i))a+=n-abs(i);
    }
    cout<<a<<endl;
}