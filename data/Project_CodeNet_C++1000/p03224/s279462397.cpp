#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#define INF 9999999
using namespace std;

int a[100000+5];
vector<int> line[500];

int main(){
    int n;
    scanf("%d",&n);
    int k=floor(sqrt(2*n)+0.5);
    if(k*(k+1)==2*n){
        int cnt=k+1;
        int t=1;
        for(int i=1;i<cnt;i++){
            int s=i*(i-1)/2+1;
            for(int j=0;j<i;j++)line[j].push_back(s++);
            for(int j=0;j<i;j++)line[i].push_back(--s);
        }
        printf("Yes\n%d\n",cnt);
        for(int i=0;i<cnt;i++){
            printf("%d",line[i].size());
            for(int j=0;j<line[i].size();j++)
                printf(" %d",line[i][j]);
            printf("\n");
        }
    }else{
        printf("No\n");
    }
}
