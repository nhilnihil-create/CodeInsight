#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<cmath>
#include<ctime>
#include<algorithm>
#include<utility>
#include<stack>
#include<queue>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#define EPS 1e-9
#define PI acos(-1.0)
#define INF 0x3f3f3f3f
#define LL long long
const int MOD = 1E9+7;
const int N = 8000+5;
const int dx[] = {-1,1,0,0,-1,-1,1,1};
const int dy[] = {0,0,-1,1,-1,1,-1,1};
using namespace std;

int x,y;
string str;
bitset<N*2> bs[2];
int main(){
    cin>>str;
    scanf("%d%d",&x,&y);

    int i=0;
    while(str[i]=='F')
        i++;
    bs[0][i+N]=1;
    bs[1][N]=1;

    int num=0;
    int pos=0;
    while(i<=str.size()){
        if(str[i]=='F')
            num++;
        else{
            bs[pos]=(bs[pos]<<num) | (bs[pos]>>num);
            pos=!pos;
            num=0;
        }
        i++;
    }

    if(bs[0][x+N] & bs[1][y+N])
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}
